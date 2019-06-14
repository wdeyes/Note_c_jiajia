# C-_node
C++笔记

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
``` c++
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
``` c++
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
``` c++
template void Swap<int>(int, int}; 
```
#### 选择题 
*c++二级考试刷题考点记录*
- 结构化程序设计的思想包括：自顶向下，逐步求精，模块化，尽量避免使用goto 
- ER图，实体联系图：矩形-实体，属性-椭圆，菱形-联系 
- 没有指明继承方式，则为私有继承 
- 模板有函数模板和类模板两种 
- cin遇到空格、teb、回车都会结束 
- const必须初始化 
- 重载运算符的函数不能有默认的参数 
- 类的静态数据成员必须在类体外进行初始化，一般为 
  `int classname::valuename=0` 
- 保护成员：派生类可以访问protected权限的成员但是派生类的对象不能访问基类的成员。 
- 默认方式为私有 
  要区分开类和对象，他们访问权限不同 
  1.公有：类和对象都可以访问 
  2.保护：类和继承类可以访问，对象不可以访问 
  3.私有：成员函数可以访问，对象不可以访问，继承类不可见 
[image:F6560540-5139-476B-B0A5-63C19B1A8C96-45614-0001E812FCD45F2B/p131.png]
|  public  | protected |  private  | Private |
| :------: | :-------: | :-------: | :-----: |
| 共有继承 |  public   | protected | 不可见  |
| 私有继承 |  private  |  private  | 不可见  |
| 保护继承 | protected | protected | 不可见  |

- 二叉树：度为0的叶子结点总比度为2的结点多一个 
- 面向对象设计的特征：对象、类、实例、消息、继承、多态性。 
- “=”、下标运算符、函数调用运算符只能作为成员函数重载 
- 虚函数不能是静态成员函数，但可以是友员函数 
- 循环队列是队列的一种顺序存储结构 
- 实体完整性：必须有一个或多个候选关键字 
- 不能被重载的运算符有五个：
` .    .*    ::    ?:    sizeof    tyeid`
- `setw()`只对当前有效，设置位宽； 
- 黑盒测试：等价类分法、边界值分析法、错误推测法 
- 函数原型声明时，指定默认参数值时，从右至左。 
- 结构化方法软件需求分析工具主要有：数据流图、数据字典、判定树、判定表。 
- 软件测试主要包括：单元测试、集成测试、确认测试、系统测试。 
- 只有类的非静态成员才有this指针。 
- 在数据流图中，用标有名字的箭头表示数据流； 
  在程序流图中，用标有名字的箭头表示控制流； 
- 常对象只能引用常成员函数； 
- 成员与数据成员的区别； 
- 派生类调用基类的构造函数时，顺序为MF; 
  `class Child :public Mother, publlic Father` 
- 数据模型通常由数据结构、数据操作及数据约束组成； 
### 大题 
- 类中成员函数：参数列表中有对象时，要加&（因为没有拷贝构造函数），注意是否加const。 
- 基类的纯虚函数声明最后要写“=0”； 
- 注意有几个new，必须有几个delete； 

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