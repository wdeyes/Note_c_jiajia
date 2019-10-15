#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
	return a.first < b.first;
}
int main(int argc, char const *argv[])
{
	int n;
	while(cin >> n){
		vector<pair<int,int> > data(n);
		for(int i=0; i<n; ++i){
			cin >> data[i].first >> data[i].second;
		}
		sort(data.begin(), data.end(), cmp);
		vector<long> temp;
		temp.push_back(0);
		for(auto val : data){
			int i=val.first, j=val.second;
			while(i<temp.size() && temp[i]!=0) {
				temp[i++] += j;
			}
			for(; i<temp.size()&&j>0; ++i){
				temp[i] += j--;
			}
			while(i>temp.size()){
				temp.push_back(0);
			}
			while(j>0){
				temp.push_back(j--);
			}
		}
		long max=0;
		for(int i=0; i<temp.size(); ++i){
			if(temp[i]>max) max=temp[i];
		}
		cout << temp.size() << " " << max << endl;
	}
	return 0;
}