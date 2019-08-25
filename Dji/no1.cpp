#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 递归，组合
void solve(vector<pair<int, int> > game, int day_num, int index, int &ans, int &max){
	if(index==game.size() && day_num>=0){
		if(ans>max)
			max = ans;
		return;	
	}
	if(index==game.size() && day_num<0)
		return ;
	

	ans += game[index].first;
	solve(game, day_num-game[index].second, index+1, ans, max);

	ans -= game[index].first;
	solve(game, day_num, index+1, ans, max);

}

// 01背包问题，动态规划
// https://www.kancloud.cn/kancloud/pack/70129
// 递推公式：f(i,v) =max( f(i-1,v), f(i-1,v-c_i)+w_i )，对于第i件物品，背包容量为v
// 优化过空间，仅使用一维数组。主要要倒着更新 j。j表示容量为j时。
// 题外话：01背包有两种：背包够放和背包恰好放满，初始化不同。对于恰好用完的情况：
// 					对于第0件，容量为0时初始为0，其余为负无穷，这样f(i,v)除非你用完v,不然+w_i也是无穷。
// 						负无穷写法：#include<limits.h> INT_MIN 表示负无穷。
//       完全背包问题：更新方向不同，对于第i件可以要0~k个。容量要顺序更新，v是逐渐增大的，
//					这样每次求最大时就包含了这件物品要g(0<g<k)件的可能。
// 					dp[v_i]=max( dp[v_i], dp[v_i-c_i]+w_i )，i在循环，dp[v_i]是上一个物品，dp[v_i-c_i]包含了当前物品。
int solve2(vector<pair<int,int> > game, int day_num, int game_num){
	vector<int> dp(day_num+1);
	for(int i=0; i<game_num; ++i){
		int cost = game[i].second;
		int value = game[i].first;
		for(int j=day_num; j>=cost; --j){
			dp[j]=max(dp[j], dp[j-cost]+value);
		}
	}
	return dp[day_num];
}

int main(int argc, char const *argv[])
{
	int case_num;
	cin >> case_num;
	for(int i=0; i<case_num; ++i){
		int game_num, day_num;
		cin >> game_num >> day_num;
		vector<pair<int ,int> > game(game_num);
		for(int i=0; i<game_num; ++i){
			cin >> game[i].first >> game[i].second;
		}
		// int max=0, ans=0;
		// solve(game, day_num, 0, ans, max);
		// cout << max << endl;
		cout << solve2(game, day_num, game_num) << endl;
	}
	return 0;
}