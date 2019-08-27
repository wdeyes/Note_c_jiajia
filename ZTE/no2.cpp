#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// 题目要求要稳定排序，所以边放到map中，边放到vector中，最后对vector排序，注意要使用stable_sort进行稳定排序，
// 用map查找快，用vector是排序用，map会打乱输入的顺序（可以看 test.cpp）
// sort 函数是主要用快排，结合了插入排序和堆排序，属于不稳定排序
/* 输入：
19
10000
20000
40000
30000
30000
30000
40000
20000
50000
50000
50000
50000
60000
60000
60000
70000
80000
90000
100000
*/

bool cmp(pair<int,int> a, pair<int,int> b){
	return a.second > b.second;
}

int main(int argc, char const *argv[])
{
	int n;
	while(cin >> n){

		unordered_map<int, int> data; // key is mony, value is people
		vector< pair<int,int> > sort_data; // first is money, second is the number of people
		for(int i=0; i<n; ++i){
			int money;
			cin >> money;
			//没有这个 money 时
			if(data.find(money)==data.end()){
				data[money]=1;
				sort_data.push_back(pair<int,int>(money,1));
			}
			//有这个 money 时
			else{
				++data[money];
				// sort_data 中改变对应的 second
				for(auto &val : sort_data)
					if(val.first==money){
						++val.second;
						break;
					}
			}
		}
		stable_sort(sort_data.begin(), sort_data.end(), cmp);
		//输出
		for(auto people : sort_data){
			for(int i=0; i<people.second; ++i)
				cout << people.first << " ";
		}
		cout << endl;

	}
	return 0;
}