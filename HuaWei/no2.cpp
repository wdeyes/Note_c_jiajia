#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_map>
using namespace std;

/*
1  2  3  4  5
11 12 13 14 15
21 22 23 24 25
31 32 33 34 35
41 42 43 44 45
如上的一个5*5矩阵，输入6个成员，判断这6个成员是否挨着。
输入：1 2 3 4 5 11，输出：1
输入：1 2 11 14 25 15，输出：0
*/

int main(int argc, char const *argv[])
{
	
	return 0;
}



//hxw 代码
int find(vector<int>&p, int num){
 if (p[num] == num)
  return num;
 return p[num] = find(p, p[num]);
}

void unite(vector<int>&p, int num1, int num2){
 int p_num1 = find(p, num1);
 int p_num2 = find(p, num2);
 p[p_num2] = p_num1;
}

int _tmain()
{
 //直接给定二维数组则要获取各个数字的位置
 vector<vector<int>> m{ { 1, 2, 3, 4, 5 }, { 11, 12, 13, 14, 15 }, { 21, 22, 23, 24, 25 }, { 31, 32, 33, 34, 35 }, { 41, 42, 43, 44, 45 } };
 unordered_map<int, int> matrix(m.size()*m[0].size());
 for (int i = 0; i<m.size(); ++i){
  for (int j = 0; j < m[0].size(); ++j){
   matrix[m[i][j]] = i * 5 + j;
  }  
 }
 int n;
 while (cin >> n){
  unordered_map<int, int> inp(n);
  vector<int> inpnum(n);
  for (int i = 0; i < n; ++i){
   cin >> inpnum[i];
   inp[inpnum[i]] = i;
  }
  int dir[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
  vector<int> p = { 0, 1, 2, 3, 4 };
  for (int i = 0; i < n; ++i){
   int pre = matrix[inpnum[i]];
   
   int x = pre / 5;
   int y = pre % 5;
   for (int j = 0; j < 4; ++j){
    int next_x = x + dir[j][0];
    int next_y = y + dir[j][1];//分别向上向下移动
    if (next_x < 0 || next_x >= 5 || next_y < 0 || next_y >= 5)//超过界限
     continue;
    if (inp.find(m[next_x][next_y]) == inp.end())
     continue;
    //输入的数字中存在当前值在给定数组中相邻的数字，将他们进行合并，将相邻的数字放到当前数字的集合中
    unite(p, inp[m[x][y]], inp[m[next_x][next_y]]);
    }
  }
    bool res = true;
  for (int i = 0; i < n; ++i){
//  cout << p[i];
   if (p[i] != p[0]){
    res = false;
    break;
   }
  }
  if (res)
   cout << 1;
  else
   cout << 0;
 }
 return 0;
}




//我最开始考虑的方法，有漏洞，不可行。
int main(int argc, char const *argv[])
{
	vector<int> nums(6);
	while(cin >> nums[0]){
		for(int i=1; i<6; ++i)
			cin >> nums[i];

		sort(nums.begin(), nums.end());
		//这里加一行
		vector<int> nums_copy=nums;

		for(int i=0; i<6; ++i){
			while(nums[i]>9)
				nums[i] %= 10;
		}
		int ans=1;
		for(int i=0; i<5; ++i){
			if(nums[i+1]-nums[i]>1){
				ans=0;
				break;
			}
		}
		//这里加一块
		if(ans==1){
			for(int i=0; i<6; ++i){
				while(nums_copy[i]>9){
					nums_copy[i] /= 10;
				}
				if(i>1 && (nums_copy[i]-nums_copy[i-1]>1) ){
					ans=0;
					break;
				}
			}
		}

		cout << ans << endl;
	}
	return 0;
}