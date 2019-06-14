# C++ STL

## vector
- 输入、输出都得循环一个一个来
- size 与 capacity 的区别，resize() 与 reserve() 的区别
## string
- `void resize(int len,char c); ` //把字符串当前大小置为len，多去少补，多出的字符c填充不足的部分
- `getline(cin, str)` 读取一行，包括空格，使用 cin，遇到空格会停止。
## Queue 队 （先进先出） 
入队，如例：q.push(x); 将x 接到队列的末端。
出队，如例：q.pop(); 弹出队列的第一个元素，注意，并不会返回被弹出元素的值。
```c++
for(int j=0;j<n;j++)
{
	e=q1.front();
	cout<<e<<" ";
	q1.pop();
}

```
访问队首元素，如例：q.front()
访问队尾元素，如例：q.back()
判断队列空，如例：q.empty()，当队列空时，返回true。
访问队列中的元素个数，如例：q.size()

## 栈stack （后进先出）
和 queue 类似，就是 front 改为 top
[CSDN](https://blog.csdn.net/qq_20366761/article/details/70053813)
## map 
存key-value数据 
根据key值快速查找记录，查找的复杂度基本是Log*(N)，如果有1000个记录，最多查找10次
[map](https://www.cnblogs.com/fnlingnzb-learner/p/5833051.html)

## set
存单一数据，每个元素唯一，自动排序，且不可直接改变。 
Map和set都是STL中关联容器，采用红黑二叉树，统计性能高效。 
## hash表
unordered_map，为了提高散列容器的性能，unordered库会在插入元素是自动增加桶的数量，不需要用户指定。但是，用户也可以在构造函数或者rehash()函数中，指定最小的桶的数量。
无序：hash函数，确定哪个桶；比较函数，在桶中寻找。
 key唯一
 常用操作:   [https://blog.csdn.net/earl211/article/details/59483651](https://blog.csdn.net/earl211/article/details/59483651)  
hash.begin()是第一个，hash.end()是最后一个的下一个。因此常用 if( hash.find(key值) != hash.end() ) 来遍历寻找




​	