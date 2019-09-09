#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
using namespace std;

int main(int argc, char const *argv[])
{
	// string str="x=1y=2";
	// string s = str.substr();
	// cout << s << endl;
	// s.clear();
	// cout << s << endl;
	// cout << "here" << endl;

	// char str[100];
	// gets(str);
	// //cin >> str;
	// cout << str << endl;

	// string str;
	// getline(cin, str);
	// cout << str << endl;


    string s = "1   23 # 4";
    cout << s.size() << " " << s.length() << endl;
    stringstream ss(s);
    //ss<<s;
    while(ss>>s){
        cout<<s<<endl;
    }

	return 0;
}