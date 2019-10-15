#include <bits/stdc++.h>
using namespace std;
//100%
bool cmp(pair<int,int> a, pair<int,int> b){
	return a.second<b.second;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	
	deque<pair<int,int> > nums(n);
	for(int i=0; i<n; ++i){
		cin >> nums[i].first >> nums[i].second;
	}
	
	sort(nums.begin(), nums.end(), cmp);
	
	int m = nums.front().second + nums.back().second;
	//cout << m << endl;

	while(!nums.empty()){
		m = max(m, (nums.front().second) + (nums.back().second) );
		nums.front().first--;
		nums.back().first--;
		if(!nums.empty() && nums.front().first<=0)
			nums.pop_front();
		if(!nums.empty() && nums.back().first<=0)
			nums.pop_back();
		// for(auto ele:nums){
		// 	cout << ele.first << " " << ele.second << endl;
		// }
	}



	cout << m << endl;
	return 0;
}



