#include <bits/stdc++.h>
using namespace std;

// 1到26对应a到z，输入一串数字的字符串，输出能得到几种可能的组合
// 输入23 输出3
// 输入273 输出1

int main(int argc, char const *argv[])
{
	string s;
	while(cin >> s){
		int n=s.size();
		if(n==0 || (n==1 && s[0]=='0') )
			cout << 0 << endl;
		else if(n==1 && s[0]!='0')
			cout << 1 << endl;
		
		else{

			vector<int> dp(n+1);
			dp[0]=1;
			if(s[0]=='0')
				dp[1]=0;
			else
				dp[1]=1;

			for(int i=2; i<=n; ++i){
				int cur = s[i-1]-'0';
				int pre = s[i-2]-'0';
				if(cur!=0)
					dp[i]=dp[i-1];

				if( (pre*10+cur)<=26 && (pre*10+cur)>9)
					dp[i] += dp[i-2];
				
				
			}
			cout << dp[n] << endl;
		}
	}
	return 0;
}