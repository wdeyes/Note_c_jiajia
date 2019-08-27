#include <iostream>
#include <vector>
using namespace std;

// 二维背包问题
// 100
// 5
// 15
// 50 40 30 20 10 
// 1 2 3 9 5
// 300 480 270 200 180

struct data
{
	int m_v;//体积
	int m_m;//重量
	int m_e;//价值
};

int main(int argc, char const *argv[])
{
	int V; // 容量
	while(cin >> V){
		int n, M; // 物品数量。重量，即第二个容量
		cin >> n >> M;
		vector<data> things(n);
		for(int i=0; i<n; ++i)
			cin >> things[i].m_v;
		for(int i=0; i<n; ++i)
			cin >> things[i].m_m;
		for(int i=0; i<n; ++i)
			cin >> things[i].m_e;

		//dp
		vector<vector<int> > dp(V+1, vector<int>(M+1) );// 0 is not used
		for(int i=0; i<n; ++i){
			int v=things[i].m_v;
			int m=things[i].m_m;
			int e=things[i].m_e;
			for(int j=V; j>0; --j){
				for(int k=M; k>0; --k){
					if(j>=v && k>=m) 
						dp[j][k] = max(dp[j][k], dp[j-v][k-m]+e);
				}
			}
		}
		cout << dp[V][M] << endl;
	}
	return 0;
}