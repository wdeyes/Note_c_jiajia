/*
实现一个循环队列类CircularQueue，其中包括：
●构造函数：传入队列的最大长度max_size。
●push_back：将元素放到队列尾。
●pop_front：将队列首元素弹出。
●batch_remove：从队列首开始移除指定数量的元素，如果队列长度小于给定数量则清空队列。
(n)。

C++:
class CircularQueue要求队列实现时使用循环队列的方式，空间占用为O {
 public:
  CircularQueue(unsigned int max_size);
  bool push_back(int item);
  bool pop_front();
  void batch_remove(unsigned int count);
};

*/


/*
实现一个队列 SPSCQueue, 支持单个生产者和单个消费者的 C++多线程程序.
    + 队列长度在一开始的构造函数中传进去
    + enqueue(int data): 生产者每次会往队列里面放一个 int, 值从 1 开始递增
    + int dequeue(): 消费者每次会从队列中拿出一个 int, 并打印, 要求和放入的顺序一致
*/
