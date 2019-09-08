#include <bits/stdc++.h>
using namespace std;

//36%，参考剑指offer的全排列（38题），然后每个都judge一次，可能是复杂度太高

bool judge(vector<int> one2n, vector<int> nums){
	for(int i=0; i<one2n.size()-1; ++i){
		if(nums[i]==1 && one2n[i+1]>one2n[i])
			return false;
		if(nums[i]==0 && one2n[i+1]<one2n[i])
			return false;
	}
	return true;
}

void core(vector<int> &one2n, int index, vector<int> nums, long &ans){
	if(index==one2n.size()-1){
		if(judge(one2n, nums))
			ans = (ans+1)%1000000007;
	}
	else{
		for(int i=index; i<one2n.size(); ++i){
			swap(one2n[index], one2n[i]);
			core(one2n, index+1, nums, ans);
			swap(one2n[index], one2n[i]);
		}
	}
}

int main(int argc, char const *argv[])
{
	int n;
	while(cin >> n){
		vector<int> nums(n-1);
		for(int i=0; i<n-1; ++i)
			cin >> nums[i];

		vector<int> one2n;
		for(int i=0; i<n; ++i)
			one2n.push_back(i+1);

		long ans=0;
		core(one2n, 0, nums, ans);
		cout << ans%1000000007 << endl;
	}
	return 0;
}