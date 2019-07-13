#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
// 输入一些整数对（ai,bi），输出一个整数对(x,y)，使得 ai==x or bi==y。没有则输出 “No”.
// 1<=ai,bi<=0^9
// 输入
// 4
// 1 5
// 3 5
// 1 3
// 5 5
// 输出
// 1 5


int main(int argc, char const *argv[])
{
	
	return 0;
}

//这个不好，太复杂，太暴力 time=O(2^n)
// bool judge(int** data, int number, int* ans){
// 	int one=data[0][0];
// 	int i=1;
// 	bool ret=true;
// 	while(data[i][0]==one && i<number)
// 		++i;
// 	if(i==number){
// 		ans[0]=one;
// 		ans[1]=one;
// 		return ret;
// 	}

// 	int other = data[i][0];
// 	ans[0]=one;
// 	ans[1]=other;
// 	++i;
// 	while(i<number){
// 		if(data[i][0]!=one && data[i][0]!=other){
// 			ret=false;
// 			ans[0]=0;
// 			ans[1]=0;
// 			break;
// 		}
// 	}
// 	return ret;
// }

// bool core(int** data, int number, int* ans, int index){
// 	if(index==number){
// 		return (judge(data, number, ans));
// 	}
// 	bool ret1=core(data, number, ans, index+1);
// 	swap(data[index][0], data[index][1]);
// 	bool ret2=core(data, number, ans, index+1);
// 	return ret1||ret2;
// }

// int main(int argc, char const *argv[])
// {
// 	int number;
// 	cin >> number;
// 	int** data=new int*[number];
// 	for(int i=0; i<number; ++i){
// 		data[i] = new int[2];
// 		cin >> data[i][0] >> data[i][1];
// 	}
// 	int* ans = new int[2];
// 	core(data, number, ans, 0);
// 	cout << ans[0] << " " << ans[1];

// 	delete[] ans;
// 	for(int i=0; i<number; ++i)
// 		delete[] data[i];
// 	delete[] data;

// 	return 0;
// }




