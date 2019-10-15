#include <bits/stdc++.h>
using namespace std;

/*
//实现lru缓存区，least recently used，最近最少使用的不要，
存key-value
输入一个数字就是get，输入两个数字就是put
输入；
2
1 1
2 2
1
3 3
输出
3 3
1 1

*/

list<int> keys;
unordered_map<int,int> value;
unordered_map<int,int> no;

int get(int key){
	if(value.find(key)==value.end())
		return -1;
	
	int n=no[key];
	no[key]=0;
	auto it = keys.begin();
	for(int i=0;i<=n;++i)
		++it;
	keys.erase(it);
	keys.push_front(key);
	return value[key];

}

void put(int n, int key, int val){
	if(value.find(key)==value.end()){
		if(keys.size()>=n){
			int temp=keys.back();
			keys.pop_back();
			value.erase(temp);
			no.erase(temp);
		}
		//cout << "size: " << value.size() << no.size() << endl;
		keys.push_front(key);
		
		value[key]=val;
			
		for(auto &ele:no)
			ele.second++;
		no[key]=0;
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	cin.get();

	string s;
	while(getline(cin, s) ){
		//cout << "shuru: " << s << endl;
		if(s.size()==0)
			break;

		if(s.size()==1){
			int k=s[0]-'0';
			int xxx=get(k);
		}
		else{
			int k=s[0]-'0';
			int v=s[2]-'0';
			put(n, k, v);
		}

		// for(auto ele:keys)
		// 	cout << ele << " ";
		// cout << endl;
		// for(auto ele:value)
		// 	cout << ele.first<<ele.second << " ";
		// cout << endl;
		// for(auto ele:no)
		// 	cout << ele.first<<ele.second << " ";
		// cout << endl;
	}

	for(auto ele:keys){

		cout << ele << " " << value[ele] << endl;
	}
	return 0;
}







