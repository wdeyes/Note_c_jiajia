#include <iostream>
using namespace std;

// 一个直角三角形三条边都为整数，输入p，输出有几种可能。
// 输入：120。
// 输出：3. 有 {20，48，52}；{24，45，51}；{30，40，50}

// https://blog.csdn.net/gooding300/article/details/86555475


//两层循环
// int main(int argc, char const *argv[])
// {
// 	int p;
// 	while(cin >> p){
// 		int ans=0;
// 		for(int a=1; a<p/3; ++a){
// 			for(int b=a+1; b<p/2; ++b){
// 				int c=p-a-b;
// 				if(a*a+b*b==c*c && a+b>c && a+c>b && b+c>a)
// 					++ans;
// 			}
// 		}
// 		cout << ans << endl;
// 	}
// 	return 0;
// }


//一层循环
int main(int argc, char const *argv[])
{
	int p;
	while(cin >> p){
		int ans=0;
		for(int a=1; a<p/3; ++a){
			double b = (double)(p*p-2*p*a)/(2*p-2*a);
			int c = p-a-b;
			//cout << a <<" "<< b << " "<< c << endl;
			if(a<b && a+b+c==p && a+b>c && a+c>b && b+c>a)
				++ans;
		}
		cout << ans << endl;
	}
	return 0;
}




