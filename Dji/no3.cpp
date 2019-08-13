//背包问题变形
// https://ac.nowcoder.com/discuss/219787?type=1
/* 题目见图片，示例:
5 2
1 2
2
2 1
输出：1
10 4
1 2 5 8
2
2 3
输出: 7
排序完为：2518，购买方案为以下7种：
1 0 0 1
1 0 8 0
2 0 6 0
2 1 1 0
3 0 4 0
4 0 2 0
5 0 0 0
*/
#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


int main(int argc, char const *argv[])
{
	int v;//能用的开销，要恰好花完
	while(cin >> v){
		int n;
		cin >> n;//n种food
		vector<int> food_temp(n);
		for(int i=0; i<n; ++i)
			cin >> food_temp[i];
		//m种特别喜欢的，放在food的前面
		int m;
		cin >> m;
		vector<int> food(n);
		for(int i=0; i<m; ++i){
			int index;
			cin >> index;
			food[i]=food_temp[index-1];
			food_temp[index-1]=-1;
		}
		for(int i=0, index=m; i<n; ++i){
			if(food_temp[i]>0) 
				food[index++]=food_temp[i];
		}
		//对于第一种特别喜欢的food，dp[i][j]二维数组，表示买i个，容量为j
		//初始化, 全买第一种food，买i个，花费i*c, 一种方案
		int c = food[0];
		vector< vector<int> > dp(v/c+1, vector<int>(v+1));
		for(int i=0; i<=v/c; ++i)
			dp[i][i*c]=1;

		//买其余特别喜欢的food，即food[1]~food[m-1]
		for(int i=1; i<m; ++i){
			vector< vector<int> > temp=move(dp);
			c=food[i];
			dp=vector< vector<int> > (v/c+1, vector<int>(v+1,0));
			//前一种food买了j个
			for(int j=1; j<temp.size(); ++j){
				//这种买k个，要比j小，
				for(int k=min(j-1,v/c); k>=0; --k){
					//计算每个v对应的值, v起码要从k*c起，这个地方v_temp可以顺序计算，因为递推式中temp是上一次的
					for(int v_temp=k*c; v_temp<=v; ++v_temp)
						dp[k][v_temp] = ( dp[k][v_temp] + temp[j][v_temp-k*c] )%10000007;
				}
			}
		}
		//合并，统计，ans[i]表示容量为i的方案数
		vector<int> ans(v+1);
		for(int i=0; i<=v; ++i){
			for(int j=0; j<dp.size(); ++j)
				ans[i] = ( ans[i] + dp[j][i] )%10000007;
		}
		//对于其余不是特别喜欢的food，完美背包问题
		for(int i=m; i<n; ++i){
			c=food[i];
			// j为容量，j小于c的不用更新；j>=c的，可以选择要这种和不要这种两种方案
			for(int j=c; j<=v; ++j)
				ans[j] = ( ans[j] + ans[j-c] )%10000007;
		}

		cout<< ans[v] << endl;
	}
	return 0;
}











