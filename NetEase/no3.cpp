// 剑指offer59题，滑动窗口的最大值，deque 双头队列，参考写出如下代码  time=O(n^2)，暴力法为O(n^3)
// https://www.nowcoder.com/discuss/216237 答案没有看懂


#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int FindMin(const vector<int> &nums, int size){
	deque<int> FrontMax; //存序号，用来判断有没有超过size

	for(int i=0; i<size; ++i){
		while(!FrontMax.empty() && nums[i]>nums[FrontMax.back()] )
			FrontMax.pop_back();
		FrontMax.push_back(i);
	}	
	int min = nums[FrontMax.front()];

	for(int i=size; i<nums.size(); ++i){
		if(i - FrontMax.front() >= size) // 超过size
			FrontMax.pop_front();

		while(!FrontMax.empty() && nums[i]>nums[FrontMax.back()] )
			FrontMax.pop_back();
		FrontMax.push_back(i);
		if(nums[FrontMax.front()] < min)
			min = nums[FrontMax.front()];
	}
	return min;	
}

int main(int argc, char const *argv[])
{
	int n;
	while(cin>>n){
		vector<int> nums(n);
		for(int i=0; i<n; ++i)
			cin >> nums[i];

		vector<int> ans;
		for(int i=1; i<=n; ++i){ //窗口长度循环
			int min = FindMin(nums, i);
			ans.push_back(min);
		}
		for(auto val : ans)
			cout << val << " ";
		cout << endl;
	}
	return 0;
}