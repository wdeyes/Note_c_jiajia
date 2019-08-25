// 体育场突然着火了，现场需要紧急疏散，但是过道真的是太窄了，同时只能容许一个人通过。
// 现在知道了体育场的所有座位分布，座位分布图是一棵树，已知每个座位上都坐了一个人，安全出口在树的根部，也就是1号结点的位置上。
// 其他节点上的人每秒都能向树根部前进一个结点，但是除了安全出口以外，没有任何一个结点可以同时容纳两个及以上的人，这就需要一种策略，
// 来使得人群尽快疏散，问在采取最优策略的情况下，体育场最快可以在多长时间内疏散完成。

// 输入：
// 第一行包含一个正整数n，即树的结点数量（1<=n<=100000）。 接下来有n-1行，每行有两个正整数x，y，表示在x和y结点之间存在一条边。(1<=x，y<=n)
// 输出：
// 输出仅包含一个正整数，表示所需要的最短时间

// 输入：
// 6
// 2 1
// 3 2
// 4 3
// 5 2
// 6 1
// 输出：4

#include<iostream>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
using namespace std;

// 参考下面的一个答案，没有树这个结构存数据，就用图，邻接表存储。
int main(int argc, char const *argv[])
{
	int n;
	while(cin >> n){
		vector<list<int> > vec(n+1);//0 is not used
		
		for(int i=0; i<n-1; ++i){
			int a,b;
			cin >> a >> b;
			vec[a].push_back(b);
			vec[b].push_back(a);
		}
		//访问记录
		vector<bool> visited(n+1, false);
		visited[1]=true;

		
		int ans = 0;
		for(auto sub_node : vec[1]){
			int count=0;
			queue<int> buff;
			buff.push(sub_node);
			while(!buff.empty()){
				int f = buff.front();
				visited[f]=true;
				++count;
				buff.pop();
				for(auto node: vec[f]){
					if(visited[node]==false)
						buff.push(node);
				}
			}
			ans = count>ans? count:ans;
		}
		cout << ans << endl;
	}
	return 0;
}

// 思路对了，就是求最大根节点的最大子树，node个数。
// 本地可以，练习题中段错误。
// int main(int argc, char const *argv[])
// {
// 	int n;
// 	while(cin >> n){
// 		vector<pair<int,int> > temp;
// 		vector< unordered_set<int> > data;

// 		for(int i=0; i<n-1; ++i){
// 			int first, second;
// 			cin >> first >> second;
// 			if(second == 1){
// 				unordered_set<int> hash;
// 				hash.insert(first);
// 				data.push_back(hash);
// 			}
// 			else{
// 				temp.push_back(pair<int,int>(first, second));
// 			}
// 		}

// 		for(auto &no_deal:temp){
// 			for(auto &deal:data){
// 				if( deal.find(no_deal.second)!=deal.end() ){
// 					deal.insert(no_deal.first);
// 					break;
					
// 				}
// 			}
// 		}

// 		int max = data[0].size();
// 		for(auto deal:data){
// 			if(deal.size()>max)
// 				max = deal.size();
// 		}
// 		cout << max << endl;

// 	}
// 	return 0;
// }






