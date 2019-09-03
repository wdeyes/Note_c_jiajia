#include <iostream>
#include <vector>
using namespace std;

void mPrint(vector<int> &nums){
	for(auto num:nums)
		cout << num << " ";
	cout << endl;
}

int main(int argc, char const *argv[])
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(6);
	nums.push_back(4);
	mPrint(nums);
	make_heap(nums.begin(), nums.end() );//使整个数组变成堆
	//make_heap(nums.begin(), nums.begin()+nums.size() );
	mPrint(nums);
	nums.push_back(5);
	// push_heap(nums.begin(), nums.end() );
	// nums.push_back(2);
	mPrint(nums);
	push_heap(nums.begin(), nums.end() );//使数组的最后一位变到合适位置，仍然符合堆
	mPrint(nums);
	pop_heap(nums.begin(), nums.end() );//使堆顶元素移动数组尾
	mPrint(nums);

	return 0;
}