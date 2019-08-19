// 一个珍珠项链，用数组表示（首位相接），长度为l，上面有n个珍珠，已知每个珍珠的位置，问最小移动多少可以将珍珠挨在一起。
// l=1000，n=4，位置分别为：1，4，998，995。输出：8. 解释：1移到0，4移到1，998移到999，995移到998.
// 目前无思路

#include <iostream>
using namespace std;

int solve(vector<int> p){
	
	int mid = (n+1)/2;
	int sum=0;
	int temp=p[mid]-1;//mid左边位置
	for(int i=mid-1; i>=0; --i){
		sum += temp-p[i];
		--tmep;
	}
	temp = p[mid]+1;//mid右边位置
	for(int i=mid+1; i<n; ++i){
		sum += p[i]-temp;
		++temp;
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	int l, n;
	while(cin >> l >> n){
		vector<int> p(n);
		for(int i=0; i<n; ++i)
			cin >> p[i];
		
		sort(p.begin(), p.end());
		
	}
	return 0;
}