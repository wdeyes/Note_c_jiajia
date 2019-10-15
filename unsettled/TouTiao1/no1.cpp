#include <bits/stdc++.h>
using namespace std;

int solve(string s){
    vector<int> nums;
    vector<char> cal;
    string temp = s;
    for(auto &ele:temp){
        if(ele>'9' || ele<'0') {
            cal.push_back(ele);
            ele=' ';
        }
    }
    stringstream ss(temp);
    string s_nums;
    while(ss>>s_nums){
        int temp=0;
        for(auto ele:s_nums)
            temp = temp*10 + ele-'0';
        nums.push_back(temp);
    }


    int ans=0;
    for(int i=0; i<cal.size(); ++i){
        if(cal[i]=='*'||cal[i]=='/'){
            int temp;
            if(cal[i]=='*'){
                temp=nums[i]*nums[i+1];
            }
            else if(cal[i]=='/')
                temp=nums[i]/nums[i+1];
            nums[i]=temp;
            for(int j=i+1;j<nums.size()-1;++j){
                nums[j]=nums[j+1];
            }
        }
    }
    int index=1;
    ans+=nums[0];
    for(int i=1;i<cal.size(); ++i){
        if(cal[i]=='+'||cal[i]=='-'){
            if(cal[i]=='+')
                ans+=nums[index];
            else if(cal[i]=='-')
                ans-=nums[index];
            ++index;
        }
    }
    return ans;
}

int main() {
    string s = "1+2*3-5";
    int ans = solve(s);
    cout << ans << endl;
    cout << "Hello World!" << endl;
}