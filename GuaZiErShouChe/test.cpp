#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 函数的参数如果是指针，传入的是不同的指针，不过指向的同一块内存，这里命名为A。
// 当用malloc时，为一个地址分配一块内存，这快内存是新分配的，不再指向 A 内存。

void getmemory(char *p){
	cout << &p << endl;
	p=(char*) malloc(100);
	strcpy(p, "hello world");
}

void change(int* p){
	cout << &p << endl;
	*p = 5;
}

int main(int argc, char const *argv[])
{
	// char str[] = "hello";
	// char* p=str;
	// int n=10;
	// cout << sizeof(str)<< endl
	// << sizeof(p) << endl
	// << sizeof(n) << endl;

	// void * p=malloc(100);
	// cout << sizeof(p)<< endl;

	char * str=new char[100];
	str[0]='h';
	cout << &str << endl; 
	getmemory(str);
	printf("%s\n", str);
	// char* h=NULL;

	char* p=NULL;
	p=(char*) malloc(100);
	strcpy(p, "hello world");

	printf("%s\n", p);
	free(str);
	free(p);

	int* n = new int;
	cout << &n << endl;
	*n = 1;
	change(n);
	cout << *n << endl;



	return 0;
}