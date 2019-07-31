#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// 参考ans2.cpp，不考虑时间复杂度的循环，要找一个好实现的循环角度

bool isHu(map<int,int> nMap){
	while(!nMap.empty()){
		auto it=nMap.begin();
		while(it->second==0){
			nMap.erase(it);
			if(nMap.empty()) return true;
			it = nMap.begin();
		}
		// it 指向的牌是目前最小的牌，从小往大找
		// 最小的牌>=3张，做刻字，小于3张做刻字，因为如果>=3张做顺子，那么它后面的两张也得是>=3，和做刻子一样
		if(it->second<3){
			int next = it->first+1;
			int nnext = it->first+2;
			if(nMap.find(next)!=nMap.end() && nMap.find(nnext)!=nMap.end() ){
				if(it->second <= nMap[next] && it->second <= nMap[nnext]){
					nMap.erase(it);
					nMap[next] -= it->second;
					nMap[nnext] -= it->second;
				}	
				else 
					return false;
			}
			else
				return false;
		}
		else
			it->second -= 3;
	}
	return nMap.empty();
}

bool judge(vector<int> nums){
	map<int, int> nMap;
	for(auto val : nums){ //vector 可以这么循环，记住
		++nMap[val];    // map本质是红黑二叉树，具有顺序，还可以这么插入，记住
	}
	// 循环尝试每个做雀头
	for(auto it=nMap.begin(); it!=nMap.end(); ++it){
		if(it->second>=2){
			it->second -= 2;
			if(isHu(nMap))  return true;
			it->second += 2;
		}
	}
	return false;
}


int main(int argc, char const *argv[])
{
	vector<int> nums(13); //0~12共13个数，都是0
	vector<int> counts(10); // 0~9共10个数，都是0
	for(int i=0; i<13; ++i){
		cin >> nums[i]; // 可以直接输入，记住
		++counts[nums[i]];
	}
	bool isHu=false;
	//循环push 1~9，尝试
	for(int i=1; i<=9; ++i){
		if(counts[i]<4){
			nums.push_back(i);
			if(judge(nums)){
				cout << i << " ";
				isHu = true;
			}
			nums.pop_back();
		}
	}
	if(!isHu) cout << '0';
	cout << endl;
	return 0;
}




