#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//字符串处理 

bool xiaoxie(string &str, int start, int end){
	bool ret=true;
	for(int i=start; i<=end; ++i){
		if(str[i]>='A' && str[i]<='Z'){
			ret=false;
			break;
		}
	}
	return ret;
}

bool daxie(string &str, int start, int end){
	bool ret=true;
	for(int i=start; i<=end; ++i){
		if(str[i]>='a' && str[i]<='z'){
			ret=false;
			break;
		}
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	string str;
	while(cin >> str){
		if(str.size()==1 )
			cout << "true" << endl;
		else{

			bool ans = true;
			if(str[0]>='a' && str[0]<='z'){
				if(xiaoxie(str, 1, str.size()-1))
					ans=true;
				else
					ans=false;
			}
			else if(str[0]>='A' && str[0]<='Z'){
				if( daxie(str, 1, str.size()-1) || xiaoxie(str, 1, str.size()-1))
					ans=true;
				else
					ans=false;
			}

			if(ans)
				cout << "true"<<endl;
			else
				cout << "false" << endl;

		}
	}
	return 0;
}