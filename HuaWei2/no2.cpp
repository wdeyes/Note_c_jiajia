#include <bits/stdc++.h>
using namespace std;

//本地试了几个可以，但通过率为0
//原因，只考虑了组合，没有考虑排列，只有旋转，翻转的视为一种

int main()
{
	int n, m;
	while(cin >> n >> m){

		// vector<vector<long> > f(n+1, vector<long>(m+1, 0));
		// for(int i=0; i<=n; ++i)
		// 	f[i][0]=1;
		// for(int i=1; i<=n; ++i){
		// 	for(int j=1; j<=m; ++j){
		// 		//要k个当前的
		// 		for(int k=0; k<=j; ++k)
		// 			f[i][j] = ( f[i][j]+f[i-1][j-k] ) %1000000007;
		// 	}
		// }
		// cout << f[n][m] << endl;

		//由上面二维可以优化为一维

		vector<long> dp(m+1);
		dp[0]=1;
		for(int i=0; i<n; ++i){
			for(int j=1; j<=m; ++j)
				dp[j] = (dp[j]+dp[j-1])%1000000007;
		}
		cout << dp[m] << endl;
	}
	return 0;
}