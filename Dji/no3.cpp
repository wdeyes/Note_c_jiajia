
//背包问题变形
#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

bool cmp(pair<int,int> num1, pair<int,int> num2){
	return num1.first > num2.first;
}

int main(int argc, char const *argv[])
{
	int v;
	while(cin >> v){
		int num;
		cin >> num;
		vector< pair<int, int> > food(num);
		//输入food的cost
		for(int i=0; i<num; ++i){
			cin >> food[i].second;
		}
		int love_num;
		cin>>love_num;//喜爱food的数目
		int daxiao=love_num;//喜爱程度
		for(int i=0; i<love_num; ++i){
			int index;
			cin >> index;
			food[index].first = daxiao;
			daxiao--;
		}
		sort(food.begin(), food.end(), cmp);
	}
	return 0;
}