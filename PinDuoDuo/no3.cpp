// n长度的数字，满足递增数列，求和为s的数列有多少种。
// n=3 s=10 输出4种，说明：有127，136，145，235。
// n=4,s=18，输出15种
#include<iostream>
#include <vector>
#include <cmath>
using namespace std;

// 参考 https://blog.csdn.net/h2453532874/article/details/99250644
// 动态规划
// 递推关系和放苹果问题类似
// dp[n][s]分为两种情况，第一位是1和第一位不是1的，
// 是1的：全部拿走1，情况种类和n-1位和为s-n的一样；
// 不是1的：全部拿走1，情况种类和n位，和为s-n的一样；
// dp[n][s] = dp[n-1][s-n] + dp[n][s-n]

int main(int argc, char const *argv[])
{
    int n;
    while(cin>>n){
        int s;
        cin >> s;
        vector< vector<int> > dp(n+1, vector<int> (s+1));
        //初始化
        for(int i=1; i<=s; ++i)
            dp[1][i]=1;

        for(int i=2; i<=n; ++i){
            //和的最小值
            int s_min=(1+i)*i/2;
            for(int j=s_min; j<=s; ++j){
                dp[i][j]=dp[i-1][j-i]+dp[i][j-i];
            }
        }
        cout << dp[n][s] << endl;
    }
    return 0;
}


// //自己考虑的动态规划，有问题，失败，no3_1.cpp改用递归
// int main(){
//     int n;
//     while(cin >> n){
//         int s;
//         cin >> s;
//         //dp[i][j]表示i位，和为j，有多少种
//         vector< vector<int> > dp(n+1, vector<int> (s+1));
//         //dp初始化
//         for(int i=1; i<=s; ++i)
//             dp[1][i]=1;

//         for(int i=2; i<=n; ++i){
//             //构成i位数字的最小 s 为 s_min
//             int s_min = (1+i)*i/2;
//             for(int j=s_min; j<=s; ++j){
//                 //分析：n位递增数列，去掉最后一位就是n-1位的递增数列，且它们和的差为最后一位的这个数
//                 // dp[i][j]表示i位，和为j有多少种
//                 //递推关系为：dp[i][j]=dp[i-1][k1]+dp[i-1][k2]+...+dp[i-1][k_up]
//                 //比如：dp[3][10]=dp[2][3]+dp[2][4]+dp[2][5]
//                 // 下限3就是构成2位的最小和，所以i-1位的最小和为(1+i-1)*(i-1)/2；
//                 // 上限5，dp[2][6]不满足，数列24，对应244不满足递增，数列15（对应154）更不满足。
//                 // i-1位和为k，则第i位是j-k, 递增需要k/2+1<j-k，这里有问题
//                 int down = (i-1)*i/2;
//                 double up = 2.0*(j-1)/3.0;
//                 int k=down;
//                 do {
//                     dp[i][j] += dp[i-1][k];
//                     ++k;
//                 }
//                 while(k<up);
//             }
//         }
//         for(auto &nums : dp){
//             for(auto &val:nums)
//                 cout << val << " ";
//             cout << endl;
//         }
//         cout << dp[n][s] << endl;
//     }
//     return 0;
// }