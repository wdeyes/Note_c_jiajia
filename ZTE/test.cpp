#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;


int main(int argc, char const *argv[])
{

	map<int, char> m;
	unordered_map<int, char> um;

	m.insert(make_pair(2, 'b') );
	m.insert(make_pair(1, 'a') );
	m.insert(make_pair(9, 'q') );
	m.insert(make_pair(8, 'w') );
	m.insert(make_pair(7, 'e') );
	m.insert(make_pair(6, 'r') );
	for(auto &val:m)
		cout << val.first << " " << val.second << endl;

	cout << "this is unordered_map: " << endl;

	um.insert(make_pair(2, 'b') );
	um.insert(make_pair(1, 'a') );
	um.insert(make_pair(9, 'q') );
	um.insert(make_pair(8, 'w') );
	um.insert(make_pair(7, 'e') );
	um.insert(make_pair(6, 'r') );
	for(auto &val:um)
		cout << val.first << " " << val.second << endl;

	return 0;
}