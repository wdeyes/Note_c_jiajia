#include <bits/stdc++.h>
using namespace std;

bool ok(set<int> &copy, int cur, int pre){
	auto it = copy.find(cur);
	if(it!=copy.begin() && *(--it)==pre )
		return true;
	return false;
}

int main(int argc, char const *argv[])
{
	int n;
	while(cin >> n){
		vector<int> nums(n);
		set<int> copy;
		for(int i=0; i<n; ++i){
			cin >> nums[i];
			copy.insert(nums[i]);
		}

		// vector<int> m(n+1, n+1);
		// for(int i=0; i<n; ++i){
		// 	*lower_bound(m.begin(), m.end(), nums[i]) = nums[i];
		// }
		// int ans = lower_bound(m.begin(), m.end(), n+1)-m.begin();
		// cout << n-ans << endl;

		
		

		vector<int> dp(n);
		dp[0]=1;
		int m=-1;
		for(int i=1; i<n; ++i){
			for(int j=0; j<i; ++j){
				if(ok(copy,nums[i], nums[j]))
					dp[i] = max(dp[i], dp[j]+1);
				else
					dp[i] = max(dp[i], dp[j]);
			}
			m = max(m ,dp[i]);
		}
		cout << n-m << endl;
	}
	return 0;
}