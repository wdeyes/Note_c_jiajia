#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    int n;
    while(cin >> n) {
        vector<int> nums(n);
        for(int i = 0; i < n; ++i) cin >> nums[i];
        int k;
        long long cnt = 0;
        cin >> k;
        if (n < 3) {
            cout << 0 << endl;
            continue;
        }
        //sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; ++i) {
            //if(i > 0 && nums[i] == nums[i-1]) continue;
            int start = i + 1, end = n - 1;
            while(start < end) {
                //if(start > i + 1 && nums[start] == nums[start-1]) {
                //    start++;
                //    continue;
                //}
                if(nums[i] + nums[start] + nums[end] >= k) 
                    end--;
                else{
                    //cout << nums[i] << " "<< nums[start] << " "<< nums[end] << " " << end-start << endl;
                    cnt += (end-start);
                    start++;
                    //break;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}