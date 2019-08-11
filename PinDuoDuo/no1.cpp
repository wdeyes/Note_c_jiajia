// 输入n个数字，找3个数字的方差最小是多少。
// 10 -1 0 1 3 输出0.67(保留小数点后)
#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <iomanip>
using namespace std;


//计算三个数字的方差
double vari(int num1, int num2, int num3){
	vector<int> nums3;
	nums3.push_back(num1);
	nums3.push_back(num2);
	nums3.push_back(num3);

	double sum=0.0;
    for(auto val:nums3)
        sum+=val;
    double ave = sum/3;

    double sum_diff=0.0;
    for(auto val:nums3){
    	sum_diff += (val-ave)*(val-ave);
    }
    double ans = sum_diff/3;
    return ans;
}

int main(int argc, char const *argv[])
{
    int n;
	while(cin>>n){
		if(n<3)
			continue;
        vector<int> nums(n);
        for(int i=0; i<n; ++i)
            cin >> nums[i];

        sort(nums.begin(), nums.end());
        double min = vari(nums[0], nums[1], nums[2]);
        for(int i=1; i<=n-3; ++i){
        	double var = vari(nums[i], nums[i+1], nums[i+2]);
        	if( var<min)
        		min = var;
        }
        cout << setiosflags(ios::fixed)<< setprecision(2) << min << endl;//笔试时错误在这里
        
    
    }
	return 0;
}

/* *****************记住****************
#include <iomanip>  

//保留小数点后2位
cout << setiosflags(ios::fixed) << setprecision(2) << val << endl;

//保留2位有效数字
cout << setprecision(2) << val << endl;

//科学计算法
cout <<setiosflags(ios::scientific) <<val << endl;
*/







