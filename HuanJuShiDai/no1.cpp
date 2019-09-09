#include <bits/stdc++.h>
using namespace std;
//删除倒数第n个节点，快慢指针就可以
//输入12345，n=2，输出：1235

int main(){
    string str;
    cin >> str;
    int n;
    cin >> n;
    
    vector<int> nums;
    for(int i=0; i<str.size(); ++i){
        if(str[i]>='0' && str[i]<='9')
            nums.push_back(str[i]-'0');
    }
    int fast=0;
    int slow=0;
    for(int i=0; i<n; ++i)
        ++fast;
    while(fast<nums.size()){
        ++fast;
        ++slow;
    }
    cout << slow << endl;
    string ans;
    for(int i=0; i<nums.size(); ++i){
        if(i!=slow){
            ans.push_back(nums[i]+'0');
            ans.push_back('-');
            ans.push_back('>');
        }
    }
    ans.pop_back();
    ans.pop_back();
    for(auto val:ans)
        cout << val;
    cout << endl;
    return 0;
}