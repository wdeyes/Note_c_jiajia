### 基础

- 只有main函数可以省略return 0； 
- 对于声明变量，尽量在首次使用前使用它； 
- 只有在定义数组时才能使用初始化，此后就不能使用了，也不能将一个数组给另一个数组； 
- 字符串给数组可以用库函数：strcpy( food,”flan”); 

### 数组

```c++
strlen（charr1）；// 
cin.getline(charr1,20);// 
strcpy(a,b); 
strcat(a,b); 
strncat(a,b,size); 
```

### 字符串： 

```c++
str1.size（）；//计算长度 
getline(cin,str1);//输入，会接收回车，可用cin.get()消除； 
```

### 注意点

- 原始字符串：

```c++
cout << R”()”; 
cout << R”+*()+*”;// 
```

- 枚举量是整型，可被提升为int类型，但int类型不能自动转换为枚举类型；

```c++
int* pt； 
pt = (int*) 0xB8000000；//强制转换 
```

```c++
include(”cstring") 

strcmp(charr1,charr2);//判断两个字符串是否相等，相等返回0 
```

- 逗号运算符等于逗号右边的值； 
- 数组从0开始，注意别越界，否则程序崩溃； 
- 加分号：创建结构，do while循环 
  不加分号：for循环，while循环，if else 
- new 对应 delete； 
- `ofstream oufile;` 
  `  outfile.open(“a.txt”); `
  对应：`outfile.close(); `
- `cctype`库在196页； 
  文件输入程序例子212页； 
- 判断条件别把==写成=； 

### 函数重载（多态） 

- 名字相同，特征标不同，即参数列表不同； 
- 引用与非引用视为同一特征标 
- 返回类型不属于特征标 

###### 函数模板 

- 具体类型->泛型 
- 隐式实例化 

```c++
template <typename T> 
void Swap(T &a, T &b); 
int main() 
{...} 
template <typename T> 
void Swap(T &a, T &b) 
{ 
T temp; 
temp = a; 
a = b; 
b = temp; 
) 
```

- 显示具体化,不用使用模板来定义，而使用自定义的 

```c++
template <typename T> 
void Swap(T &a, T &b); 
struct job 
{ 
... 
}; 
template <> void Swap<job> (job &j1, job &j2); 
int main() 
{...} 
template <> void Swap<job> (job &j1, job &j2) 
{...} 
```

- 显示实例化（使用模板） 

```c++
template void Swap<int>(int, int}; 
```

### 知识点

- “>>””<<“ 二进制下的右移和左移； 
- ^ 异或 不同等于1，相同等于0； 
- [C++中创建二维数组的四种方法 - j的博客 - CSDN博客](https://blog.csdn.net/bqw18744018044/article/details/81665898)
- 动态数组没有长度，静态数组长度求法：`sizeof(nums)/sizeof(nums[0])`
  但是初始化时必须有长度：`int* nums = new int[10]; delete[] nums;`
- 编译多个 cpp 要链接：
  [Linux下g++编译与使用静态库和动态库 - Sean.W的专栏 - CSDN博客](https://blog.csdn.net/seanwang_25/article/details/20702751)
  [在linux下使用gcc/g++编译多个.h .c 文件 - 简书](https://www.jianshu.com/p/e5c6a255076b)
- 异常处理
  [C++ 异常处理 | 菜鸟教程](http://www.runoob.com/cplusplus/cpp-exceptions-handling.html)
  注意 catch 的一定要是 const 

```c++
#include<exception>
//你的代码
if(...){
	throw "error";
}
//你的代码
try{
	...
}
catch(const char* msg){
	cerr << msg << endl;
}

```

