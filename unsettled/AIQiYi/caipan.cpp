#include <bits/stdc++.h>
using namespace std;

//9月18日，帮别人看的一道题
int ok(const vector<int> &nums){
	int i=0;
	for(; i<nums.size(); ++i){
		if(nums[i]!=0) break;
	}
	return i;
}

void down(vector<int> &nums, int i){
	for(int j=0; j<nums.size(); ++j){
		if(j!=i && nums[j]>0)
			--nums[j];
	}
}

int main(int argc, char const *argv[])
{
	int n;
	while(cin >> n){
		vector<int> nums(n);
		for(int i=0;i<n;++i)
			cin >> nums[i];

		sort(nums.begin(), nums.end() );
		int ans=0;
		int i=ok(nums);
		while( i != nums.size() ){
			down(nums, 0);
			for(auto ele:nums)
				cout << ele << " ";
			cout << endl;
			++ans;
			sort(nums.begin(), nums.end() );
			i=ok(nums);
			cout << i << endl;
			
		}
		cout << ans << endl;
	}
	return 0;
}
