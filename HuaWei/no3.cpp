#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
两个数组，元素唯一且无序，问最少删除几个元素，使两个数组剩下的部分一样。
输入：1 3 5 2 和 3 2 1 5，输出：2

解法
https://www.nowcoder.com/discuss/236906?type=post&order=time&pos=&page=1
lower_bound 用法如下，返回第一个大于等于的地址
upper_bound 返回第一个大于的地址
https://www.cnblogs.com/Tang-tangt/p/9291018.html

思路：索引的最长递增子序列
*/



int main(int argc, char const *argv[])
{
	int n;
	while(cin >> n){
		vector<int> a(n), b(n), order(n);
		unordered_map<int, int> mmap;
		for(int i=0; i<n; ++i){
			cin >> a[i];
			mmap[a[i]]=i;
		}
		for(int i=0; i<n; ++i){
			cin >> b[i];
			order[i] = mmap[b[i]];
		}
		//求order的最长递增子序列
		vector<int> temp(100000, 100000);
		for(int i=0; i<n; ++i){
			*lower_bound(temp.begin(), temp.end(), order[i]) = order[i];
		}
		int max_l = lower_bound(temp.begin(), temp.end(), 100000)-temp.begin();
		cout << n-max_l << endl;
	}
	return 0;
}