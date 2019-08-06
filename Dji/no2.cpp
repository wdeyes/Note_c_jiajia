#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


int main(int argc, char const *argv[])
{
	int n ,m;
	while(cin >> n){
		cin >> m;
		//vector< pair<string, string> > p(n);
		unordered_map<string, string> hash;
		for(int i=0; i<n; ++i){
			string cmd, action;
			cin >> cmd >> action;
			hash[cmd] = action;
			//cin >> p[i].first >> p[i].second;
		}
		vector<string> p_cmd(m);
		for(int i=0; i<m; ++i){
			cin >> p_cmd[i];
		}
		for(auto val : p_cmd){
			if(hash.find(val)!=hash.end()){
				auto it = hash.find(val);
				cout << it->second << endl;
			}
		}
	}
	return 0;
}