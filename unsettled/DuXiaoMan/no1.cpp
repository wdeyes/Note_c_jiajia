#include <bits/stdc++.h>
using namespace std;

bool xless0(vector<pair<int,int> > &data){
	for(auto &val : data){
		if(val.first<0){
			for(auto & num:data)
				++num.first;
			return true;
		}
	}
	return false;
}

bool yless0(vector<pair<int,int> > &data){
	for(auto &val : data){
		if(val.second<0){
			for(auto & num:data)
				++num.second;
			return true;
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int x, y, n;
	while(cin >> x >> y>> n){
		vector<pair<int,int> > data(n);
		for(int i=0; i<n; ++i){
			cout << "**" << endl;
			cin >> data[i].first >> data[i].second;
		}
	
		while(x<0 || xless0(data)){
			++x;
		}
		while(y<0 || yless0(data)){
			++y;
		}
		int xmax=x, ymax=y;
		for(auto val:data){
			if(val.first>xmax) xmax=val.first;
			if(val.second>ymax) ymax=val.second;
		}
		vector<vector<int> > dp(xmax+2, vector<int>(ymax+2, 0));
		for(auto val:data)
			dp[val.first][val.second] = 10000;

		for(int i=0; i<=xmax+1; ++i){
			for(int j=0; j<ymax; ++j){
				if(i==0 && j!=0){
					dp[i][j] = min(dp[i+1][j], dp[i][j-1])+1;
				}
				else if(i!=0 && j==0)
					dp[i][j] = min(dp[i-1][j], dp[i][j+1])+1;
				else if(i!=0 && j!=0)
					dp[i][j] = min(dp[i-1][j], dp[i][j-1])+1;
			}
		}

		cout <<"ans: "<< dp[x][y] << endl;

	}

	return 0;
}





