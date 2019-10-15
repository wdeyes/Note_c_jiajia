#include <iostream>
#include <string.h>
#include <map>
using namespace std;
 
string MaxSubStr(string str){
    int len = str.length();
    int* dp = new int[len+1];
    dp[1] = (str[0] - '0') == 1?1:-1;
    for(int i = 2;i <= len;i++){
        dp[i] = (str[i-1] - '0') == 1?1:-1;
        dp[i] += dp[i-1];
    }
    int start = 0,end = 0,max = 0,begin;
    map<int,int> m;
    for(int i = 1;i <= len;i++){
        begin = m[dp[i]];
        if(begin == 0 && dp[i] != 0){
            m[dp[i]] = i;
        }
        else{
            if(i - begin > max){
                max = i - begin;
                start = begin;
                end = i;
            }
        }
    }
    return str.substr(start,max);
}
 
int main(){
    int n;
    while(cin >> n){
        string s;
        cin >> s;
        if(MaxSubStr(s).size() < n)
            cout<< MaxSubStr(s).size() + 1 <<endl;
        else
            cout<< MaxSubStr(s).size() <<endl;
    }
    return 0;
}