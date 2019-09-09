#include <bits/stdc++.h>
using namespace std;

//字符串中全是数字，去重输出，要求数字小，还不能交换位置
//输入876678，输出678
//

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
void core(string &str, int index, unordered_map<char,int> &mmap, string &ans){
	if(index>=str.size()){
		if(judge(str, ans))
			ans = str;
		//return;
	}
	else{
		if(mmap.find(str[index])!=mmap.end()){
			string temp = str;
			//cout << index << " " << temp << endl;
			str.erase(index, 1);
			core(str, index, mmap, ans);
			str = temp;
			str.erase(mmap[str[index]], 1);
			core(str, index, mmap, ans);
		}
		else{
			mmap[str[index]]=index;
			core(str, index+1, mmap, ans);
		}
	}
}

int main(int argc, char const *argv[])
{
	string str;
	cin >> str;
	unordered_map<char,int> mmap;
	string ans;
	//cout << str << str.size() << str[5] << endl;
	core(str, 0, mmap, ans);
	
	//cout << ans << endl;
	for(int i=0; i<ans.size(); ++i)
		cout << ans[i];
	cout << endl;

	return 0;
}





