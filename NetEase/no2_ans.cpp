// 首先要明白利用位运算枚举所有子集 https://blog.csdn.net/Mtrix/article/details/61200302
// for(int i=x; i; i=(i-1)&x) 复杂度为x子集个数。

// 本题思路为：设一个数组p[]，进来一个x，枚举x的超集，也就是x可能会产生的集合。方法如下：
// 		本来为32位二进制，现在拿8位举例，例如x=00110001，设mx=11111111，
// 		s=x^mx=11001110，也就是x取反。然后枚举s的子集，比如i=10000000就是一个子集，i^x=10110001，得到x的超集。
// 		超集也就是x与某个数或某些数取或运算得到的集合。
// 		p[]的下标就是超集，也就是可能出现的答案，value为旧x与新x取或，当value等于下标，则输出YES。


#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	// pow(2,17)=131072, pow(2,16)=65536, 题中1<=x<=100000, 因此要用mx=131071=hx(1ffff)，所以就要用131072大小的数组
	vector<int> p(131072);
	int mx = 131071;
	int q;
	cin >> q;
	while(q--){
		int op, x;
		cin >> op >> x;
		if(op==1){
			if(p[x]==x)  //存过x
				continue;
			int s=x^mx;
			for(int i=s; i; i=(i-1)&s){ //i为s的子集，i^x就是x的超集
				p[i^x] |= x;
			}
			p[x]=x;
		}
		else if(op==2){
			if(p[x]==x)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}