#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

//失败，正确的参考no2.cpp
//失败原因
//没有考虑后面可能有空格，cin遇到空格会断开，用getline或者gets


int deal(string & str, unordered_map<string, int> & mmap){
	int index=0;
	while(str[index]==' ')
		++index;
	int end=index;
	while(str[end]!='=')
		++end;
	++end;
	//cout << "end" << end << endl;
	string temp = str.substr(index, end-1);
	int ntemp=0;
	while(str[end]>='0' && str[end]<='9'){
		ntemp = ntemp*10 + str[end] - '0';
		//cout << "ntemp:" << ntemp << endl;
		++end;
	}
	while(str[end]=='+'){
		int ntemp2 = 0;
		++end;
		while(str[end]>='0' && str[end]<='9'){
			ntemp2 = ntemp2*10 + str[end] - '0';
			++end;
		}
		//cout << "ntemp2" << ntemp2 << endl;
		ntemp += ntemp2;
	}
	mmap[temp] = ntemp;
	return ntemp;
}

int deal_final(string & str, unordered_map<string, int> & mmap){
	int index=0;
	int ret=0;
	while(str[index]!='=')
		++index;
	++index;
	string temp;
	while(str[index]!='\0'){
		
		while(str[index]!='+' && str[index]!='\0'){
			temp+=str[index];
			//cout << temp;
			++index;
		}
		//cout << temp << " " << mmap[temp] << endl;
		ret += mmap[temp];
		temp.clear();
		++index;
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	int n;
	while(cin >> n){
		vector<string> data(n);
		for(int i=0; i<n; ++i){
			cin >> data[i];
		}
		unordered_map<string, int> mmap;
		int ans=0;
		for(int i=0; i<n-1; ++i){

			deal(data[i], mmap);
		}
		// for(auto v : mmap)
		// 	cout << v.first << " " << v.second << endl;
		//cout << data[n-1] << endl;
		ans = deal_final(data[n-1], mmap);
		//cout << "here" << endl;
		cout << ans << endl;
	}
	return 0;
}