#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	while(cin >> n){
		if(n==0)
			cout << 0 << endl;
		else{
			vector<int> nums(n);
			for(int i=0; i<n; ++i)
				cin >> nums[i];

			vector<unordered_map<int,int> > dp(n);
			int ans =1;
			for(int i=0 ;i<n ; ++i){
				for(int j=0; j<i; ++j){
					int diff = nums[i] - nums[j];
					if(dp[j][diff])
						dp[i][diff] = dp[j][diff] + 1;//这里应该错了，不同的j可能算出不同的dp[i][diff]
					else
						dp[i][diff] = 2;
					ans = max (dp[i][diff], ans);
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}