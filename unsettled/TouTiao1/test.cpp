#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	for(auto ele:nums)
		cout << ele << " ";
	cout << endl;

	nums.erase(2);

	for(auto ele:nums)
		cout << ele << " ";
	cout << endl;
	
	return 0;
}