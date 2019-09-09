#include <bits/stdc++.h>
using namespace std;
/*
括号：统计两种括号，括号匹配。
引号：统计引号个数为变量个数2倍。
逗号：统计逗号和冒号的总个数，总个数为变量数减1。


{
    "people":[
    {
        "f":"b",
        "l":"c"
    ,
    {
        "f":"b",
        "l":"c
    }
    ]
}

输出：23
*/

bool match(char left, char right, const vector<char> &bracket){
    stack<char> st;
    for(int i=0; i<bracket.size(); ++i){
        if(bracket[i]==left)
            st.push(left);
        else if(bracket[i]==right){
            if(st.empty() || st.top()!=left)
                return false;
            st.pop();
        }
    }
    if(!st.empty())
        return false;
    return true;
}

bool isBracket(char c){
    if(c=='{' || c=='}' || c=='[' || c==']')
        return true;
    return false;
}


int main(int argc, char const *argv[])
{
	string str;
    vector<char> bracket;//括号
    int quotation=0;//引号
    int comma=0;//逗号
    int var=0;
    //读一行
    while(getline(cin, str)){
        if(str.size()==0)
                break;
        for(int i=0; i<str.size(); ++i){
            if(!isalpha(str[i])){//不是字母
                if(isBracket(str[i]))
                    bracket.push_back(str[i]);
                else if(str[i]=='"')
                    ++quotation;
                else if(str[i]==',' || str[i]==':')
                    ++comma;
                str[i]=' ';//除了变量全部变成空格
            }
        }
        //计算变量数
        stringstream ss(str);
        string temp;
        while(ss >> temp) ++var;
    }
    vector<int> ans;
    if(!match('[', ']', bracket))
        ans.push_back(1);
    if(!match('{', '}', bracket))
        ans.push_back(2);
    if(quotation!=2*var)
        ans.push_back(3);
    if(comma+1 != var)
        ans.push_back(4);

    if(ans.size()==0)
        cout << 0 << endl;
    else{
        for(auto val : ans)
            cout << val;
        cout << endl;
    }
	return 0;
}




/*

//
bool is_match(char x, char y, vector<char>& bound)
{
    stack<char> st;
    for(int i=0; i<bound.size(); i++)
    {
        if(bound[i] == x)
            st.push(bound[i]);
        if(bound[i] == y)
        {
            if(st.empty() || st.top()!=x)
                return false;
            st.pop();
        }
    }
    if(!st.empty())
        return false;
    return true;
}

bool is_bound(char c)
{
    if(c == '{' || c == '}' || c == ']' || c == '[')
        return true;
    return false;
}

int main()
{
    while(1){
        vector<char> bound;
        int cnt_yin =0, cnt_d = 0, cnt_var = 0;
        string str;
        while(getline(cin, str)){
            if(!str.length())
                break;
            for(int i=0; i<str.length(); i++){
                if(!isalpha(str[i])){    //大写字母返回1，小写字母返回2，其余返回0
                    if(is_bound(str[i]))    //括号
                        bound.push_back(str[i]);
                    if(str[i] == '"')
                        cnt_yin++;
                    if(str[i] == ',' || str[i] == ':')
                        cnt_d++;
                    str[i] = ' ';//
                }
            }
            stringstream ss(str);   //向ss流中传str
            string tmp;
            //ss >> tmp是一个简单的提取
            while(ss >> tmp)    //字符串流的下一个是字符串的话,累加，中间以空格分割
                cnt_var++;
        }
        vector<int> ans;
        if(!is_match('[', ']', bound))
            ans.push_back(1);
        if(!is_match('{', '}', bound))
            ans.push_back(2);
        if(2*cnt_var != cnt_yin)    //引号是字符串个数的两倍
            ans.push_back(3);
        if(cnt_var-1 != cnt_d)      //字符串个数减一等于逗号和冒号个数
            ans.push_back(4);

        if(!ans.size())
            cout << '0';
        else{
            for(int i=0; i<ans.size(); i++)
                cout << ans[i];
        }
        cout << endl;
    }
}


*/







