#include<iostream>
#include<cmath>
using namespace std;
//输入一个N，1<=N<=10^18，如果它可以开根号就开根号，否则就 -1，问：经过多少次操作这个数变到1。
// 输入 
// 10
// 输出
// 5
// 因为 10->9->3>->2->1


int main(int argc, char const *argv[])
{
	unsigned long long a;
	while(cin>>a){
		int cot=0;
		while(a!=1){
			int s=sqrt(a);
			if(s*s==a) {
				a=s;
				++cot;
			}
			else{
				cot =cot + a-s*s+(s!=1);
				a=s;
			}
		}
		cout << cot << endl;
	}
	return 0;
}