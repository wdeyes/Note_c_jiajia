// 辗转相除法就是不停的取余，原理：设gcd(a,b)为a,b的余数，则gcd(a,b)=gcd(b, a%b)，可以用递归实现，也可以用循环实现
// 结束条件：直到其中一个为0
// 分析本题：首先，两个输入，一个超过 long long 范围，另一个没有超过，因此只要将超范围的a%b一次，a就符合范围了
// 处理方法：从高位开始取模，难点
// 特别注意：字符变整数要记得： -'0'

#include <iostream>
#include <string>
using namespace std;

unsigned long long gcd(unsigned long long a, unsigned long long b){
	return b==0? a : gcd(b, a%b);
}

int main(int argc, char const *argv[])
{
	string str;
	while(cin >> str){
		unsigned long long a, b=0;
		cin >> a;
		// 处理str，本题难点所在
		for(int i=0; i<str.size(); ++i ){
			b = (b*10 + str[i]-'0') % a;
		}
		cout << gcd(a, b) << endl;
	}
	return 0;
}