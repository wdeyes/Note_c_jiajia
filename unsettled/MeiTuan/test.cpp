#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	// list<int> nums;
	// nums.push_back(1);
	// nums.push_back(2);
	// nums.push_back(3);

	// //nums.erase(++nums.begin());
	// //auto it = nums.find(2);
	// //cout << nums[0];
	// auto it = nums.begin();
	// ++it;
	// nums.erase(it);

	// for(auto ele:nums)
	// 	cout << ele << endl;


	unordered_map<int,int> mmap;
	mmap[1]=2;
	mmap[3]=4;
	mmap.erase(1);

	for(auto ele:mmap)
		cout << ele.first << endl;

	return 0;
}