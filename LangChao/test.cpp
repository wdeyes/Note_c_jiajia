#include<bits/stdc++.h>
using namespace std;

// class A{
// public:
// 	A(){cout<<"*";}
// };

// class A{
// 	int n;
// public:
// 	A(int x=0):n(x){}
// 	void f2(int x){n=x;}
// };
// class B:private A{
// 	int m;
// 	A a;
// public:
// 	B(int b, int c):A(b) {m=c;}
// 	void f1(int i, int j){
// 		f2(i);
// 		m=j;
// 	}
// };

class A{
public:
	static int x;
};
int A::x=0;
int main(int argc, char const *argv[])
{
	// A a,b[3],&c=a,*p=new A;

	// int array[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	// cout << *(*(array+2)+3);

	//const int *a=0;
	//const int &a;
	cout << A::x << endl;
	return 0;
}



