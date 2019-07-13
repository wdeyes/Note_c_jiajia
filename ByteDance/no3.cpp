#include<iostream>
#include<cmath>
using namespace std;
//y^2 = n+ x^2，输入一个正整数 n，问存在的最小 x 是多少，不存在输出 -1。
//第一行输入有多少个n
// 输入
// 2
// 2
// 3
// 输出
// -1
// 1

int main(int argc, char const *argv[])
{
	// int number;
	// cin >> number;
	// for(int i=0; i<number; ++i){
	// 	int n;
	// 	cin>> n;
	// 	int ret=-1;
	// 	for(int j=1; j<n/2+1; j++){
	// 		int other=n/j;
	// 		if(j*other == n && abs((j-other)%2)==0){
	// 			int temp=abs(j-other)/2;
	// 			if(ret<0)
	// 				ret=temp;
	// 			else
	// 				ret=temp<ret?temp:ret;
	// 		}
	// 	}
	// 	cout << ret << endl;
	// }

	int number;
	cin>>number;
	for(int index=0; index<number; ++index){
		int n;
		cin >> n;
		int ans=-1;

		int i=sqrt(n);
		if(i*i==n) --i;

		for(;i>0; --i){
			int DoubleX = n-i*i; 
			if(DoubleX%(2*i)==0){
				ans = DoubleX/(2*i);
				break;
			}
		}
		cout << ans << endl;
	}

	return 0;
}












