#include <bits/stdc++.h>
using namespace std;
//60% 其余超时
int main(int argc, char const *argv[])
{
	int n;
	while(cin >> n){
		vector<int> a(n), b(n);
		for(int i=0; i<n; ++i)
			cin >> a[i];
		for(int i=0; i<n; ++i)
			cin >> b[i];
		int ans=0;
		for(int i=0; i<n; ++i){
			for(int j=0; j<n; ++j){
				int sum = a[i]+b[j];
				ans = ans ^ sum;
			}
		}
		cout << ans << endl;
	}
	return 0;
}