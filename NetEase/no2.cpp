#include <iostream>
#include <vector>

using namespace std;
// 这个地方不好，应该先判断有没有，没有再插入，可以改为set类型
void insert(vector<unsigned int > &jihe, unsigned int x){
    jihe.push_back(x);
}

// 参考剑指offer的38题扩展题，利用组合遍历尝试每一种或运算。
bool core(vector<unsigned int > &jihe, int i, int needlen, vector<unsigned int > &ans, unsigned int x){
    if(needlen == 0){
        int sum=0;
        for(auto it=ans.begin(); it!=ans.end(); ++it)
            sum |= *it;
        if(sum == x)
            return true;
        else
            return false;
    }
    if(i >= jihe.size())
        return false;

    ans.push_back(jihe[i]);
    if( core(jihe, i+1, needlen-1, ans, x) )
        return true;

    ans.pop_back();
    if (core(jihe, i+1, needlen, ans, x) )
        return true;

    return false;
}

bool haveSubjihe(vector<unsigned int > &jihe, unsigned int x){
    //组合问题
    for(int i = 1; i <= jihe.size(); ++i){
        vector<unsigned int > ans;
        if( core(jihe, 0, i, ans, x) )
            return true;  
    }
    return false;
}

void Myfunction(vector<unsigned int > &jihe, int mode, unsigned int x){
    if(x < 1 || x > 100000) 
        return;

    if(mode == 1)
        insert(jihe, x);
    else if(mode == 2){
        if(haveSubjihe(jihe, x))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

int main(){
    vector<unsigned int > jihe;
    unsigned int q, x;
    int mode;
    cin >> q;
    while(q--){
        cin >> mode >> x;
        Myfunction(jihe, mode, x);
    }
 
    return 0;
}








