// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <string>
// #include <cmath>

#include <bits/stdc++.h>
using namespace std;

//方法1：类似第一次华为机考的第一题，用关系式遍历
// int main(int argc, char const *argv[])
// {
// 	int n;
// 	while(cin >> n){
// 		int ans=-1;
// 		int max4=n/4;
// 		for(int i=0; i<=max4; ++i){
// 			double j = (double)(n-4*i)/9;
// 			if( (int)j==j ){
// 			//if( abs((int)j-j)<1e-5){
// 				ans=i+j;
// 				//cout << i << " " << j << endl;
// 				break;
// 			}
// 		}
// 		cout << ans << endl;
// 	}
// 	return 0;
// }


//方法2：动态规划
int main(int argc, char const *argv[])
{
	int n;
	vector<int> temp{4,9};
	while(cin >> n){
		//刚好情况要这么初始化
		vector<int> dp(n+1, n+1);
		dp[0]=0;

		for(int i=0; i<2; ++i){
			int v = temp[i];
			for(int j=v; j<=n; ++j)
				dp[j] = min(dp[j], dp[j-v]+1);
		}

		if(dp[n]==n+1) 
			cout << -1 << endl;
		else 
			cout << dp[n] << endl;

	}
	return 0;
}



