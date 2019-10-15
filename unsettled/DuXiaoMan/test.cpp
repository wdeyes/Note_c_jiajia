#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(4);
	nums.push_back(6);
	nums.push_back(8);
	cout << max(nums[1], nums[3]);
	return 0;
}