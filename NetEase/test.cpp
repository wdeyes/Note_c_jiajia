#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int nums[10];
	memset(nums, 0, sizeof(int)*10);
//	fill(nums, nums+10, 0);
	for(int i=0; i<10; ++i){
		cout << nums[i] << endl;
	}
	
	int x=131071;
	cout << bitset<sizeof(int)*8>(x) << endl;
	cout << hex << x << endl;
    cout << pow(2,16) << endl;
	cout << "long's size: " << sizeof(long) << endl;
	return 0;
}
