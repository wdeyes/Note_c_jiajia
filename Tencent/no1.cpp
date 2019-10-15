#include <bits/stdc++.h>
using namespace std;
//90%
int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	vector<string> ans;
	for(int index=0; index<t; ++index){
		int n;
		string s;
		cin >> n >> s;

		int i=0;
		for(; i<n; ++i){
			if(s[i]=='8') break;
		}
		int len = n-i;
		if(len>=11)
			ans.push_back("YES");
			//cout << "YES" << endl;
		else
			ans.push_back("NO");
			//cout << "NO" << endl;
	}
	for(auto ele:ans)
		cout << ele << endl;
	return 0;
}