
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool ishu(vector<int>num)
{
    if (num.empty())
        return true;
    int count0 = 0;
    for(int i=0;i<num.size();++i)
    {
        if (num[0] == num[i])
            ++count0;
        else
            break;
    }
    if (num.size() % 3 != 0 && count0 >= 2)
    {
        vector<int> newnum(num.begin() + 2, num.end());
        if (ishu(newnum))
            return true;
    }
    if (count0 >= 3)
    {
        vector<int> newnum(num.begin() + 3, num.end());
        if (ishu(newnum))
            return true;
    }
    if(count(num.begin(),num.end(),num[0]+1)>0 && count(num.begin(), num.end(), num[0] + 2)>0)
    {
        vector<int> newnum(num.begin() + 1, num.end());
        newnum.erase(find(newnum.begin(), newnum.end(), num[0] + 1));
        newnum.erase(find(newnum.begin(), newnum.end(), num[0] + 2));
        if (ishu(newnum))
            return true;
    }
    return false;
}
bool hupai(vector<int>num, int n)
{
    if (count(num.begin(), num.end(), n) == 4)
        return false;
    num.push_back(n);
    sort(num.begin(),num.end());
    return ishu(num);
}
int main()
{
    vector<int> num;
    vector<int> res;
    for (int i = 0; i < 13; ++i)
    {
        int tmp;
        cin >> tmp;
        if (tmp > 0 && tmp < 10)
            num.push_back(tmp);
        else
        {
            cout << "输入错误" << endl;
            return 0;
        }
    }
    for (int n = 1; n < 10; ++n)
    {
        if (hupai(num, n))
            res.push_back(n);
    }
    if (res.empty())
        cout << 0;
    else
        for (int i = 0; i < res.size(); ++i)
            cout << res[i]<<" ";
}