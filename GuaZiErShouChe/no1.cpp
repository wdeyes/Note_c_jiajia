#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//可以暴力两个数两个数的比较，n^2。下面采用从最长的距离开始暴力，也是n^2，但是可能会提前break
int main(int argc, char const *argv[])
{
	int n;
	while(cin >> n){
		vector<int> nums(n);
		for(int i=0; i<n; ++i)
			cin >> nums[i];

		int ans=0;
		for(int d=nums.size()-1; d>=1; --d){
			for(int i=0; i+d<nums.size(); ++i){
				if(nums[i]<=nums[i+d]){
					//cout << i << d << endl;
					ans=d;
					break;
				}
			}
			if(ans>0) break;
		}
		cout << ans << endl;
	}
	return 0;
}



// 这样做有漏洞，前后两个下标一起向中间移动，遗漏了一个在中间，一个在尾部的情况
// int main(int argc, char const *argv[])
// {
// 	int n;
// 	while(cin >> n){
// 		vector<int> nums(n);
// 		for(int i=0; i<n; ++i){
// 			cin >> nums[i];
// 		}

// 		int i=0, j=n-1, ans=0;
// 		while(i<j){
// 			if(nums[i]<nums[j]){
// 				ans=j-i;
// 				break;
// 			}
// 			if(nums[i+1]<=nums[j]){
// 				ans=j-i-1;
// 				break;
// 			}
// 			if(nums[i]<=nums[j-1]){
// 				ans=j-1-i;
// 				break;
// 			}
// 			++i;
// 			--j;
// 		}
// 		cout << ans << endl;
// 	}
// 	return 0;
// }

