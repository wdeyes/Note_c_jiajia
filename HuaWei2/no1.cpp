#include <stdio.h>
#include<iostream>
#include<string.h>
#include<stack>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> nums;
    int temp;
    while(cin >> temp)
        nums.push_back(temp);

    int len = nums.size();
    int ans = 100;
    for(int i=1; i<len/2; ++i){
        //cout << i << endl;
        int next = i;
        int count=1;
        while(next<len-1){
            next = next + nums[next];
            ++count;
            if(next==len-1)
                ans = min(ans, count);
        }
    }

    if(ans!=100)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}



// int main()
// {
//  vector<int> v;
//  int n;
//  while (cin>>n)
//  {
//   v.push_back(n);
//  }
//  int ans =100;
//  int len = v.size();
//  for (int i = 1; i != len / 2; i++)
//  {
//   int tem = i;
//   int j = 1;
//   while (tem<len-1)
//   {
   
//    tem = tem + v[tem];
//    j++;
//    if (tem == len-1)
//     ans = min(ans, j);
//   }
//  }
//  if (ans == 100)
//   cout << -1;
//  else
//   cout << ans;
// }