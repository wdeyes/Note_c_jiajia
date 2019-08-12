// n长度的数字，满足递增数列，求和为s的数列有多少种。
// n=3 s=10 输出4种，说明：有127，136，145，235。
// n=4,s=18，输出15种
#include<iostream>
#include <vector>
#include <cmath>
using namespace std;

//从最后一位开始递归的找


int core(int n, int s, int end){
    if(s<=0)
        return 0;
    if(n==1){
        if(s<end)
            return 1;
        else
            return 0;
    }
    int ans=0;
    //i最大就是end-1
    int i=end-1;
    while( (i-n+1+i-1)*(i-1)/2 >= (s-i)){
        ans += core(n-1, s-i, i);
        --i;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int n;
    while(cin>>n){
        int s;
        cin >> s;
        int min_sum = (1+n-1)*(n-1)/2;
        //i为最后一位，最大的可能就是s-min_sum
        int i=s-min_sum;
        int ans=0;
        //i最大的可能需要满足while中的条件，n-1位能写出最大的和要>=(s-i)，最大和为 i-n+1 ~ i-1 累加，用数字试一下就明白了
        while( (i-n+1+i-1)*(i-1)/2 >= (s-i) ){
            ans += core(n-1, s-i, i);
            --i;
        }
        cout << ans << endl;
    }
    return 0;
}
