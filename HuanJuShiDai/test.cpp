#include <bits/stdc++.h>
using namespace std;

bool judge(string str, string ans){
	if(ans.size()==0)
		return true;
	bool ret=false;
	for(int i=0; i<str.size(); ++i){
		if(str[i]<ans[i]){
			ret=true;
			break;
		}
		else if(str[i]>ans[i]){
			ret=false;
			break;
		}
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	string str = "hello";
	// str.erase(2, 1);
	// cout << str << endl;
	string s1 = "876";
	string s2 = "678";
	cout << judge(s2, s1) << endl;
	return 0;
}