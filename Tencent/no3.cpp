#include <bits/stdc++.h>
using namespace std;
/*
2
4
5 9 4 7
8
9 13 18 10 12 4 18 3

out:

12 13
43 44
*/


/*

动态规划，用历史经验更新新的

//突然有了灵感，这个方法好，不用看下面那两个方法了。
这个就是01背包问题的延伸，sum为全部分数的和，有一个容量为sum/2的背包，
有n件商品，每件价值就是分数，cost也是分数，
买n/2件商品，在容量内最多装多少。dp[v][j]就是容量为v，买j件时最多的价值。

*/

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	for(int index=0; index<t; ++index){
		int n;
		cin >> n;
		
		vector<int> point(n);
		int sum=0;
		for(int i=0; i<n; ++i){
			cin >> point[i];
			sum += point[i];
		}
		int V=sum/2;
		vector<vector<int> > dp(V+1, vector<int>(n/2+1));
		for(int i=0; i<n; ++i){
			for(int v=V; v>=point[i]; --v){ //这里倒着更新，因为是01问题
				for(int j=1; j<=n/2; ++j)
					//下面两个选择：不要i，要i
					dp[v][j] = max(dp[v][j], dp[v-point[i]][j-1] + point[i]);
			}
		}
		int small = dp[V][n/2];
		int big = sum - small;
		
		cout << small << " " << big << endl;
	}
	return 0;
}




//  https://zhuanlan.zhihu.com/p/20038650
//参考这个网页写的，失败，样例不通过
/*
int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	for(int index=0; index<t; ++index){
		int n;
		cin >> n;
		
		vector<int> point(n);
		int sum=0;
		for(int i=0; i<n; ++i){
			cin >> point[i];
			sum += point[i];
		}
		//dp[i][j][k] a组分数为i，到第j个人，a组k个人时，a组比b组多dp分
		// i:0<=i<=sum  j:0<=j<n  k:0<=k<n/2
		// 求：min[ |dp[i][n-1][n/2-1]| ]
		unordered_map<int, unordered_map<int, unordered_map<int,int> > > dp;
		//初始化，第一个人放a组，放b组
		dp[point[0]][0][1] = point[0];
		dp[0][0][0] = -point[0];
		int mi = sum;
		int ans = 0;
		for(int i=0; i<=sum; ++i){
			for(int k=0; k<n/2; ++k){
				for(int j=0; j<n; ++j){
					//放a组
					dp[i+point[j+1]][j+1][k+1] = dp[i][j][k] + point[j+1];
					//放b组
					dp[i][j+1][k] = dp[i][j][k] - point[j+1];

					if(j==n-1 && k==n/2-1){
						if(abs(dp[i][j][k])<mi && i!=0){
							mi = abs(dp[i][j][k]);
							ans = i;
						}
					}
				}
			}
		}
		int ans2 = sum - ans;
		if(ans>ans2) swap(ans, ans2);
		cout << ans << " " << ans2 << endl;
	}
	return 0;
}


*/



// 0%  错误的方法，样例可以过
/*
int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	for(int index=0; index<t; ++index){
		int n;
		cin >> n;
		vector<int> nums(n);
		int sum=0;
		for(int i=0; i<n; ++i){
			cin >> nums[i];
			sum += nums[i];
		}
		sort(nums.begin(), nums.end() );
		int goal=sum/2;
		int pre=0;
		int temp=0;
		for(int i=0; i<n/2; ++i){
			pre=temp;
			temp += nums[i];
			temp += nums[n-i-1];
			if(temp>goal) break;
		}

		int small = min(pre, temp);
		if(pre==0)
			small = temp;
		int big = sum - small;
		if(small>big) swap(small, big);
		cout << small << " " << big << endl;
	}
	return 0;
}

*/




