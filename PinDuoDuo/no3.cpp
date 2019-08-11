// n长度的数字，满足递增数列，求和为s的数列有多少种。
// n=3 s=10 输出4
#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <iomanip>
using namespace std;

void core(int s, int n, int index, int &ans){
    if(index>=n)
        return;
    if(s==0 && index<n){
        ans+=1;
        return;
    }
    if(s<0 && index<n)
        return;

    for(int i=0; i<s; ++i){
        if(s<i*n) break;
        core(s-i*n, n, index+1, ans);
    }
    
}

int main(){
    int n;
    while(cin >> n){
        int s;
        cin >> s;
        int sum = (1+n)*n/2;
        if(s<sum)
            cout << 0 << endl;
        vector<int> nums(n);
       
        int ans=0;
        core(s-sum, n, 0, ans);
        cout << ans << endl;
    }
    return 0;
}