#include <bits/stdc++.h>
using namespace std;



int main(int argc, char const *argv[])
{
	int n;
	while(cin >> n){
		if(n<=2)
			cout << n << endl;
		else{

			vector<int> nums(n);
			for(int i=0; i<n; ++i)
				cin >> nums[i];
			
			
			sort(nums.begin(), nums.end());

			vector<vector<int> > dp(n, vector<int> (n, 1));//这里错了，dp[end][diff]的diff很多
			for(int i=0; i<n; ++i)
				dp[i][n-1] = 2;
			
			int ans=-1;

			for(int i=1; i<n; ++i){
				for(int j=i-1; j>=0; --j){
					int diff = nums[i]-nums[j];
					dp[i][diff] = dp[j][diff]+1;//这里应该错了，不同的j可能算出不同的dp[i][diff]
					ans=max(ans, dp[i][diff]);
				}
			}
			cout << ans << endl;

		}

	}
	return 0;
}