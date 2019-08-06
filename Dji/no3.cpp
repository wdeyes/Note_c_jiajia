#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

bool cmp(vector<pair<int,int> > num1, vector<pair<int,int> > num2){
	return num1.first > num2.first;
}

int main(int argc, char const *argv[])
{
	int val;
	while(cin >> val){
		int num;
		cin >> num;
		vector< pair<int, int> > food(num);
		for(int i=0; i<num; ++i){
			cin >> food[i].second;
		}
		int love_num;
		cin>>love_num;
		int daxiao=love_num;
		for(int i=0; i<love_num; ++i){
			int temp;
			cin >> temp;
			food[temp].first = daxiao;
			daxiao--;
		}
		sort(food, food+num, cmp);
	}
	return 0;
}