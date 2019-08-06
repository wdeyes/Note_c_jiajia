#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(vector<pair<int, int> > game, int day_num, int index, int &ans, int &max){
	if(index==game.size() && day_num>=0){
		if(ans>max)
			max = ans;
		return;	
	}
	if(index==game.size() && day_num<0)
		return ;
	
	// day_num -= game[index].second;
	// ai += game[index].first;
	ans += game[index].first;
	solve(game, day_num-game[index].second, index+1, ans, max);
	//day_num += game[index].second;
	//ai -= game[index].first;
	ans -= game[index].first;
	solve(game, day_num, index+1, ans, max);

}

int main(int argc, char const *argv[])
{
	int case_num;
	cin >> case_num;
	for(int i=0; i<case_num; ++i){
		int game_num, day_num;
		cin >> game_num >> day_num;
		vector<pair<int ,int> > game(game_num);
		for(int i=0; i<game_num; ++i){
			cin >> game[i].first >> game[i].second;
		}
		int max=0, ans=0;
		solve(game, day_num, 0, ans, max);
		cout << max << endl;
	}
	return 0;
}