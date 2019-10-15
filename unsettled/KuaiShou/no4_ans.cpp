#include <bits/stdc++.h>
using namespace std;


/*

https://leetcode-cn.com/problems/longest-arithmetic-sequence/comments/
参考LeetCode1027题的评论答案

*/

int main(int argc, char const *argv[])
{
	int n;
	while(cin >> n){
		vector<int> nums(n);
		for(int i=0; i<n; ++i)
			cin >> nums[i];

		sort(nums.begin(), nums.end() );

		int ret=0;
		unordered_map<int ,unordered_map<int, int> > dp;

		for(int end=1; end<n; ++end){
			for(int i=0; i<end; ++i){
				int diff = nums[end] - nums[i];
				if(dp[i][diff]>0)
					dp[end][diff]=max(dp[i][diff]+1, dp[end][diff]);

				if(dp[end][diff]==0)
					dp[end][diff]=2;

				ret = max(ret, dp[end][diff]);
			}
		}
		cout << ret << endl;
	}	
	return 0;
}