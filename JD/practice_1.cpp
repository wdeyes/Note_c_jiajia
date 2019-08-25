// 京东2019春招c++软开，笔试题第一道编程题，练习一下。
// 给出m个字符串S1，S2，...，Sm和一个单独的字符串T。请在T中选出尽可能多的子串同时满足：  
// 1）这些子串在T中互不相交。  2）这些子串都是S1，S2，...，Sm中的某个串。  问最多能选出多少个子串。

// 输入：
// 第一行一个数m（1≤m≤10），接下来m行，每行一个串。最后一行输入一个串T。输入中所有单个串的长度不超过100000，串中只会出现小写字母。
// 输出：
// 输出一个数，最多能选出多少串。

// 输入：
// 3
// aa
// b
// ac
// bbaac
// 输出：
// 3
#include<iostream>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// 贪心，多个s串按长度排序，在T中先找短的
bool cmp(string a, string b){
	return a.size()<b.size();
}
int main(int argc, char const *argv[])
{
	int n;
	while(cin >> n){
		vector<string> s(n);
		for(int i=0; i<n; ++i)
			cin >> s[i];
		string T;
		cin >> T;
		sort(s.begin(), s.end(), cmp );

		int ans=0;
		for(int i=0; i<n; ++i){
			size_t pos = 0;
			// find找不到就输出 string::npos
			while( (pos=T.find(s[i], pos)) != string::npos ){
				ans++;
				// replace 从pos开始，size个，都替换成“0”
				T.replace(pos, s[i].size(), "0");
			}
		}
		cout << ans << endl;
	}	
	return 0;
}


// 自己的思路,递归解决。超时。
// int sovle(unordered_set<string> &hash, string &T, string temp, int index){
// 	string sub = temp + T[index];

// 	if(index == T.size()-1){
// 		if(hash.find(sub)!=hash.end())
// 			return 1;
// 		else
// 			return 0;
// 	}

// 	if(hash.find(sub)!=hash.end()){
// 		return 1+sovle(hash, T, "", index+1);
// 	}
// 	else{
// 		int need = sovle(hash, T, sub, index+1);
// 		int not_need = sovle(hash, T, "", index+1);
// 		return max(need, not_need);
		
// 	}
// }

// int main(int argc, char const *argv[])
// {
// 	int n;
// 	while(cin >> n){
// 		unordered_set<string> hash;
// 		string str;
// 		for(int i=0; i<n; ++i){
// 			cin >> str;
// 			hash.insert(str);	
// 		}
// 		string T;
// 		cin >> T;
// 		int ans = sovle(hash, T, "", 0);
// 		cout << ans << endl;
// 	}
// 	return 0;
// }