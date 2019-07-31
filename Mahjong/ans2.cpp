#include<iostream>
#include<vector>
#include<map>
using namespace std;

bool C(map<int,int> intMap){
	while(!intMap.empty()){
		auto ite = intMap.begin();
		while(ite->second==0){
			intMap.erase(ite);
			if(intMap.empty()) return true;
			ite = intMap.begin();
		}
		if(ite->second<3){ //此时当前牌只能是顺子
			int m = ite->second;
			if(intMap.find(ite->first+1)!=intMap.end() && intMap.find(ite->first+2)!=intMap.end()){
				m = min(m, min(intMap[ite->first+1], intMap[ite->first+2]));
				if(m==ite->second){
					intMap[ite->first+1] -= m;
					intMap[ite->first+2] -= m;
					intMap.erase(ite);
				}else{
					return false;
				}
			}else return false;
		}else{
			// 若当前牌是刻子，直接-3
			// 若当前牌是刻子+顺子，直接-3,转化为全是顺子的情况
			// 若当前牌是顺子， 则相邻三个数的次数均>=3,等价于3个刻子+顺子，最终转化为ite->second<3的情况
			ite->second -= 3;
		}
	}
	return intMap.empty();
}


bool judge(vector<int> nums){
	map<int,int> intMap;
	// 循环放入map
	for(auto val : nums) intMap[val]++;
	// 循环作为雀头
	for(auto ite=intMap.begin(); ite!=intMap.end(); ite++){
		if(ite->second>=2){
			ite->second -= 2;
			if(C(intMap)) return true;
			ite->second += 2;
		}
	}
	return false;
}


int main(){
	vector<int> nums(13);
	vector<int> count(10);
	for(int i=0; i<13; i++){
		cin>>nums[i]; 
		count[nums[i]]++;
	}
	for(int i=1; i<=9; i++){
		if(count[i]<4){
			nums.push_back(i); //循环放入9种牌，看哪一个能糊
			if(judge(nums)) cout<<i<<' ';
			nums.pop_back();
		}
	}
	cout<<endl;
	return 0;
}