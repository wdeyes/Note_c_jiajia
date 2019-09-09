#include <bits/stdc++.h>
using namespace std;

//输入：n=7，1234567，m=2,输出：3456712

int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;
	vector<int> nums(n);
	for(int i=0; i<n; ++i)
		cin >> nums[i];

	vector<int> ans;
	for(int i=m; i<n; ++i){
		ans.push_back(nums[i]);
	}
	for(int i=0; i<m; ++i)
		ans.push_back(nums[i]);
	for(auto val:ans)
		cout << val << " ";
	cout << endl;
	return 0;
}