#include <iostream>
#include <exception>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

const int MAX_PRODUCT=100;

// 循环队列基础上（模板类改为 int，去掉 batch_emove() 函数）实现单生产者单消费者，多线程程序
// 互斥锁，条件锁
class CircularQueue{
public:
	CircularQueue(unsigned int max_size)
		:max_size(max_size), m_front(0), m_rear(0){
		m_data = new int[max_size];
	}
	~CircularQueue(){
		delete[] m_data;
	}

	bool IsEmpty(){
		if(m_front==m_rear)
			return true;
		return false;
	}
	bool IsFull(){
		if( (m_rear+1)%max_size == m_front)
			return true;
		return false;
	}
	bool IsNoFull(){
		return !IsFull();
	}

	void push_back(int ele);
	int pop_front();
	void produce();
	void consume();

private:
	unsigned int max_size;
	int m_front;
	int m_rear;
	int* m_data;

	mutex mtx;
	condition_variable condi_no_empty;
	condition_variable condi_no_full;
};

void CircularQueue::push_back(int ele){
	if(IsFull())
		throw "Full!!";
	m_data[m_rear]=ele;
	m_rear = (m_rear+1)%max_size;
}

int CircularQueue::pop_front(){
	if(IsEmpty())
		throw "Empty!!";
	int temp = m_data[m_front];
	m_front = (m_front+1)%max_size;
	return temp;
}


// 生产
void CircularQueue::produce(){
	//循环一直生产
	for(int i=1; i<=MAX_PRODUCT; ++i){
		// 锁
		unique_lock<mutex> lck(mtx);

		// 堵塞，wait 的两种写法都可以
		// while(IsFull()){
		// 	cout << "Buffer is full, so wait ... " << endl;
		// 	condi_no_full.wait(lck);
		// }
		condi_no_full.wait(lck, [this]{return !IsFull();} );

		//生产
		push_back(i);
		// 唤醒消费的堵塞线程
		condi_no_empty.notify_one();
	}
}

// 消费
void CircularQueue::consume(){
	for(int i=1; i<=MAX_PRODUCT; ++i){
		unique_lock<mutex> lck(mtx);
		
		// while(IsEmpty()){
		// 	cout << "Buffer is empty, so wait ... " << endl;
		// 	condi_no_empty.wait(lck);
		// }
		condi_no_full.wait(lck, [this]{return !IsEmpty();});

		cout << pop_front() << endl;
		condi_no_full.notify_one();
	}
}



int main(int argc, char const *argv[])
{
	
	try{
		CircularQueue buffer(5);
		std::thread t1(&CircularQueue::produce, &buffer);
		std::thread t2(&CircularQueue::consume, &buffer);
		t1.join();
		t2.join();

	}
	catch(const char* msg){
		cerr << msg << endl;
	}
	return 0;
}


















