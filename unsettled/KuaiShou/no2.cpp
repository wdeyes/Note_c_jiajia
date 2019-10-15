#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
// vector<string> combination(string digits) {
//     if(digits.empty()) return {};
//     vector<string> ls{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
//     vector<string> res,temp{""};
//     for(int i=0;i<digits.size();++i){
//         res.clear();
//         int index=digits[i]-'0';
//         for(auto ele:temp)
//             for(int j=0;j<ls[index-2].size();++j)
//                 res.push_back(ele+ls[index-2][j]);
//         temp=res;
//     }
//     return res;
// }

// int main() {
//     string s;
//     while(getline(cin, s)) {
//         vector<string> res = combination(s);
//         cout << "[" ;
//         for(int i = 0; i < res.size(); ++i) {
//             cout << res[i] << ", ";
//         } 
//         cout << "]" << endl;
//     }
//     return 0;
// }



//自己基于上面代码优化，使用旋转数组，节省拷贝时间
int main(int argc, char const *argv[])
{
    string s;
    while(cin >> s){
        vector<vector<string> > ans(2);//两个，利用one，other旋转使用
        int one=0, other=1;
        ans[other].push_back("");
        vector<string> match={"", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };

        for(int i=0; i<s.size(); ++i){
            ans[one].clear();
            int n = s[i]-'0';
            for(auto ele : ans[other]){
                for(int j=0; j<match[n].size(); ++j)
                    ans[one].push_back(ele+match[n][j]);
            }
            swap(one, other);
        }
        //输出ans[other]
        cout<< "[";
        for(auto ele:ans[other])
            cout << ele << ", ";
        cout << "]" << endl;
    }
    return 0;
}





















