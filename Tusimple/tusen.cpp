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

再写吗？
zai 
c++
C++ 和 C哪个更顺手？
好 继续
en
*/

class SPSCQueue{
  public:
    SPSCQueue(int num)max(num){}
    enqueue(int data);
    int dequeue();
    down(int* x ){
      if(x==1)  
        --x;
      else
        wait(); //直到x为1
    }
    up(int* x){
      if(x==0)
        ++x;
    }
  
  private:
    int max;
    queue<int> datas(max);
    int mutex = 1;
    int empty = 1;
    int full = 0;
};
//生产者
SPSCQueue::enqueue(int data){
  down(empty);
  down(mutex);

  if(!full) {
    int pre = datas.back();
    data += 1;
  }
  else
    data=1;

    down(mutex);
    if(mutex)
      datas.push_back(data);
    up(mutex);

  //解锁
  up(mutex);
  if(datas.size()==max)
    up(full);  
}
//消费者
int SPSCQueue::dequeue(){
    down(full); 
    down(mutex);
    cout << data.front();
    datas.pop();
    up(mutex);
    if(datas.empty())
      up(empty);

}



