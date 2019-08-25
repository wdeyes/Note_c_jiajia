#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// 测试用例
// 4
// 2 1 3 2
// 输出：2
// 7
// 5 10 2 6 11 13 12
// 输出：3

//参考牛客一个人的思路，对对碰。
//未排序时的分组，与已经排序的分组，相比，每个分组里面的元素是一一对应的。
// 2 1 3 2 分组：21 32
// 1 2 2 3 分组：12 23
int main(int argc, char const *argv[])
{
	int n;
	while(cin >> n){
		vector<int> nums(n);
		for(int i=0; i<n; ++i)
			cin >> nums[i];
		// copy 数组，并且将它排序
		vector<int> copy=nums;
		sort(copy.begin(), copy.end() );
		// 
		unordered_set<int> one2one;

		int ans=0;
		for(int i=0; i<n; ++i){
			//插入未排序数组
			if(one2one.find(nums[i])==one2one.end() )
				one2one.insert(nums[i]);
			else
				one2one.erase(nums[i]);
			//插入已排序数组
			if(one2one.find(copy[i])==one2one.end() )
				one2one.insert(copy[i]);
			else
				one2one.erase(copy[i]);
			//如果数组为空，则分好一组
			if(one2one.empty())
				ans+=1;
		}
		cout << ans << endl;
	}
	return 0;
}








