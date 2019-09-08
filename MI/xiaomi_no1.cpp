#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 有n件商品，恰好花完v，最少买几件

int main(int argc, char const *argv[])
{
	int n;
	while(cin >> n){
		vector<int> price(n);
		for(int i=0; i<n; ++i)
			cin >> price[i];
		int V;
		cin >> V;
		//刚好花完要这么初始化, V+1只是为了一个大数，不能用INT_MAX,因为它+1就变成了负数
		vector<int> dp(V+1, V+1);
		dp[0]=0;
		//遍历n件商品
		for(int i=0; i<n; ++i){
			int v = price[i];
			for(int j=v; j<=V; ++j){
				//不买 买 两种情况
					dp[j] = min(dp[j], dp[j-v]+1);
			}
		}
		if(dp[V]!=V+1)
			cout << dp[V] << endl;
		else
			cout << -1 << endl;
	}

	return 0;
}