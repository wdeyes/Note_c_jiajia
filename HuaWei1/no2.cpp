#include <bits/stdc++.h>
using namespace std;

//处理一行，分割字符串，去掉空格，等号，加号，将其余元素存到 part 中
// vector<string> deal(string str){
// 	vector<string> part;
// 	int len = str.size();
// 	for(int i=0; i<len; ++i){
// 		//去掉空格
// 		while(i<len && str[i]==' ') ++i;
// 		int start = i;
// 		while(i<len && (str[i]!='=' && str[i]!='+') ) ++i;
// 		int end = i;
// 		//空格回退
// 		while(str[end-1]==' ') --end;
// 		string temp = str.substr(start, end-start);//substr（开始，长度）
// 		part.push_back(temp);
// 	}
// 	return part;
// }

vector<string> deal(string str){
    for(auto & val : str)
        if(val=='=' || val=='+')
            val = ' ';

    vector<string> part;
    stringstream ss(str);
    string temp;
    while(ss >> temp)
        part.push_back(temp);
    return part;
}

//计算一行,从第二个元素开始进行累加，结果赋给 ans
bool calc(vector<string> &part, unordered_map<string, int> &data, int &ans){
	int len = part.size();
	ans = 0;
	for(int i=1; i<len; ++i){
		//这个元素为数字 正
		if(part[i][0]>='1' && part[i][0]<='9'){
			int temp=0;
			for(auto val : part[i])
				temp = temp*10 + val-'0';
			ans += temp;
		}
		//数字，负数
		else if(part[i][0]=='-'){
			int temp=0;
			for(int j=1; j<part[i].size(); ++j)
				temp = temp*10 + part[i][j]-'0';
			ans -= temp;
		}
		//变量
		else{
			if(data.find(part[i])==data.end()){
				return false;
			}
			else
				ans += data[part[i]];
		}
	}
	//计算完存入data
	data[part[0]] = ans;
	return true;

}


int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	cin.get();//消除流中的换行，下面要用getline，否则报段错误
	//输入一个样例，遍历n行
	unordered_map<string, int> data;
	int final_ans=0;
	bool can_calc;
	for(int i=0; i<n; ++i){
		string str;
		getline(cin, str);//不可以用cin，因为遇到空格会断掉
		vector<string> part = deal(str);
		can_calc = calc(part, data, final_ans);
	}
	if(can_calc)
		cout << final_ans << endl;
	else
		cout << "NA" << endl;
	return 0;
}



//ljy参考牛客编写，参考思路，优化写法，如上
/*

int main()
{
 int n;
 //while(scanf("%d\n", &n)){
 	while(cin >> n){
  map<string, int> is;
  map<string, int> val;
  string ans;
  //输入每行表达式并处理
  for(int i = 0; i < n; ++i){
   //char s[10000];
   string s;
   //gets(s);
   getline(cin, s);
   //int s_len = strlen(s);
   int s_len = s.size();
   int j = 0;


   //分割字符串
   vector<string> var;
   while(j < s_len){   
    while(j < s_len && s[j] == ' ') ++j; //忽略表达式前空格
    if(j == s_len) break;

    int pre = j;
    while(j < s_len && (s[j] != '=' && s[j] != '+')) ++j; //遇到等号
    while(s[j-1] == ' ') --j; //回退到空格前
    char v[10000];//定义用于存储分割字符串的数组 
    int v_len = 0;
    for(int k = pre; k < j; ++k)
     v[v_len++] = s[k];
    v[j] = '\0';
    string vtemp(v);
    var.push_back(vtemp);

    while(j < s_len && s[j] == ' ') ++j;
    ++j;
   }



   int sum = 0;
   int flag = 0;
   //等号右边，所以p从1开始
   for(int p = 1; p < var.size(); ++p){
   	//数字
    if(var[p][0] >= '1' && var[p][0] <= '9'){
     int convtoint = 0;
     for(int q = 0; q < var[p].size(); ++q)
      convtoint = convtoint * 10 + var[p][q] - '0';    
     sum += convtoint;
     continue;
    }
    //减号
    if(var[p][0] == '-'){
     int convtoint = 0;
     for(int q = 1; q < var[p].size(); ++q)
      convtoint = convtoint * 10 + var[p][q] - '0';
     sum += -convtoint;
     continue;
    }
    //不是数字，看有没有储存过
    if(is[var[p]] == 1){
     sum += val[var[p]];
     continue;
    }
    if(is[var[p]] == 0){
     flag = 1;
     break;
    }
   }


   //存储
   ans = var[0];
   if(flag == 0){
    is[ans] = 1;
    val[ans] = sum;
   }
  }


  if(!is[ans])
   cout << "NA" << endl;
  else
   cout << val[ans] << endl;

 }
 return 0;
}


*/




