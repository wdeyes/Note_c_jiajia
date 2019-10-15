#include <bits/stdc++.h>
using namespace std;
//内存超了
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<int> nums;
	for(int index=0; index<n; ++index){
		int people, time;
		cin >> people >> time;
		for(int i=0; i<people; ++i)
			nums.push_back(time);
	}
	sort(nums.begin(), nums.end());
	int len=nums.size();
	int m=nums[0]+nums[len-1];
	for(int i=0; i<len/2; ++i){
		m=max(m, nums[i]+nums[len-i-1]);
		cout << nums[i]+nums[len-i-1] << endl;
	}
	cout << m << endl;

	return 0;
}