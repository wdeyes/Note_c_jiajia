#include <bits/stdc++.h>
using namespace std;

int knapSack(int n, int c, vector<int> weight, vector<int> value, vector<int> & x){
	vector<vector<int> > dp(n+1, vector<int>(c+1));
	for(int =1; i<n; ++i){
		for(int j=1; j<=c; ++j){
			if(j<weight[i-1])
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i-1]]+value[i-1])
		}
	}

	for
}

int main(int argc, char const *argv[])
{
	int n;
	while(cin >> n){
		vector<int> nums(n);
		for(int i=0; i<n; ++i)
			cin >> nums[i];
		vector<int> copy = nums;

	}
	return 0;
}