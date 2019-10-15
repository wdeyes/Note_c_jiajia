#include <bits/stdc++.h>
using namespace std;

/*
字符串处理新用法：

string str;
string substr;
char c;

1. isalnum(c), isalpha(c), isdigit(c),
2. getline(ss, str, ".")
3. str.find(c)==string::npos
	size_t st = str.find(substr)



*/

const string validIPv6Chars = "0123456789abcdefABCDEF";

bool isValidIPv4Block(string & block){
	int num=0;
	int n = block.size();
	if(n > 0 && n <= 3){
		for(int i=0; i<n; ++i){
			char c= block[i];
			if(!isalnum(c) || (i==0&&c=='0'&&n>1))
				return false;
			else{
				num *= 10;
				num += c-'0';
			}
		}
		return num <= 255;
	}
	return false;
}

bool isValidIPv6Block(string & block){
	int n = block.size();
	if(n > 0 && n <= 4){
		for(int i=0; i<n; ++i){
			char c = block[i];
			if(validIPv6Chars.find(c) == string::npos)
				return false;
		}
		return true;
	}
	return false;
}

string validIPAddress(string IP){
	string ans[3] = {"IPv4", "IPv6", "Neither"};
	stringstream ss(IP);
	string block;

	if(IP.substr(0,4).find('.')!=string::npos){
		for(int i=0; i<4; ++i){
			if(!getline(ss, block, '.') || !isValidIPv4Block(block))
				return ans[2];
		}
		return ss.eof()? ans[0] : ans[2];
	}
	else if(IP.substr(0,5).find(':')!=string::npos){
		for(int i=0; i<8; ++i){
			if(!getline(ss, block, ':') || !isValidIPv6Block(block))
				return ans[2];
		}
		return ss.eof()? ans[1] : ans[2];
	}
	return ans[2];
}

int main(int argc, char const *argv[])
{	
	string s;
	while(getline(cin, s)){
		cout << validIPAddress(s) << endl;
	}
	
	return 0;
}


