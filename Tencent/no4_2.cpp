#include<iostream>
#include<vector>
#include<string>
using namespace std;
//100%
int main() {
    int m,n;
    while(cin >> m >> n) {
        vector<int> nums(m);
        for(int i = 0; i < m; ++i){
            cin >> nums[i];
        }
        sort(nums.begin(),nums.end());
        int temp = 0, k = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int t = nums[i] - temp;
            cout << t << endl;
            ++k;
            temp += t;
            if(k >= n) break;
        }
        if(k < n) {
            for(int i = k; i < n; ++i){
                cout << 0 << endl;
            }
        }
    }
    return 0;
}