#include <iostream>
using namespace std;

// To execute C++, please define "int main()"

// The TestCase is shown below
// Input : 1 2
// Output : 3

int partation(vector<int> &nums , int start, int end){
    int small = start-1;
    for(int i=start;i<end;++i){
    	if(nums[i]<nums[end]){
            ++small;
            swap(nums[small], nums[i]);
        }    
    }
    ++samll;
    swap(nums[small], nums[end]);
    return small;
}
void core(vector<int> &nums, int k, int start, int end){
    int index = partation(nums, start, end);
    if(end-index==k)
        return;
    
    if(end-index>k)
        core(nums, k, index, end);
    else if(end-index<k)
        core(nums, k-index, start, index);
}

void solve(vector<int> nums, int k){
    core(nums, k, 0, nums.size()-1);
}

int main() {
	string words = "Hello, World!";
	cout << words << endl;
	int a, b;
	while(cin>> a >> b)
	cout << "Your result is : "<< a + b << endl;
  	return 0;
}