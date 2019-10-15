#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{


	// string s;
	// while(cin >> s){
	// 	stringstream ss(s);

	// 	string str;
	// 	getline(ss , str, '?');
	// 	cout << str << endl;
	// 	if(ss.eof())
	// 		cout << "eof"<< endl;


	// 	string str2;
	// 	getline(ss, str);
	// 	cout << str << endl;
	// 	if(ss.eof())
	// 		cout << "eof"<< endl;
				
	// }





	// string check = "aBc123";
	// for(auto ele : check){
	// 	if(isdigit(ele))
	// 		cout << "digit" << endl;
	// 	else if(isalpha(ele))
	// 		cout << "alpha" << endl;

	// 	if(isalnum(ele))
	// 		cout << "it is also alnum" << endl;
	// }



	string str="abchelloABC";
	string substr = "ello";
	size_t n= str.find(substr);
	cout << n << endl;



	return 0;
}



















