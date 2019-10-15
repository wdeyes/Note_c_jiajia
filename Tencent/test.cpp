#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	// deque<int> nums(3);
	// nums[0]=1;
	// nums[1]=2;
	// nums[2]=3;

	// while(!nums.empty()){
	// 	nums.front()--;
	// 	cout << nums.front() << endl;
	// 	if(nums.front()==0)
	// 		nums.pop_front();
	// }
	// // nums.pop_back();
	// // nums.pop_front();
	// // nums.back()--;
	// for(auto ele:nums)
	// 	cout << ele << endl;


	unordered_map<int,unordered_map<int,int> > mmp;
	mmp[0][0]=1;
	for(auto ele:mmp.second)
		cout << ele.second << endl;
	return 0;
}