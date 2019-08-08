#include <iostream>
#include <exception>
using namespace std;

// 模板函数实现循环队列
template<typename T> 
class CircularQueue{
public:
	CircularQueue(unsigned int max_size): max_size(max_size), m_front(0), m_rear(0){
		m_data = new T[max_size];
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
	void push_back(T ele);
	T pop_front();
	void batch_emove(unsigned int num_del);

private:
	unsigned int max_size;
	int m_front;
	int m_rear;
	T* m_data;
};

template<typename T>
void CircularQueue<T>::push_back(T ele){
	if(IsFull())
		throw "Full!!";
	m_data[m_rear]=ele;
	m_rear = (m_rear+1)%max_size;
}

template<typename T>
T CircularQueue<T>::pop_front(){
	if(IsEmpty())
		throw "Empty!!";
	T temp = m_data[m_front];
	m_front = (m_front+1)%max_size;
	return temp;
}

template<typename T>
void CircularQueue<T>::batch_emove(unsigned int num_del){
	if(IsEmpty())
		return;

	//计算队列中有元素的长度
	int len;
	if(m_front>m_rear)
		len=m_rear+max_size-m_front;
	else
		len=m_rear-m_front;
	// 弹出
	if(num_del>len){
		m_front=m_rear;
	}
	else
		m_front = (m_front+num_del)%max_size;
}


int main(int argc, char const *argv[])
{
	CircularQueue<int> circ_que(5);
	try{
		circ_que.push_back(1);
		circ_que.push_back(2);
		circ_que.push_back(3);
		circ_que.push_back(4);
		circ_que.pop_front();
		circ_que.batch_emove(3);
		circ_que.push_back(5);

		//circ_que.push_back(1);
		circ_que.push_back(2);
		circ_que.push_back(3);
		circ_que.push_back(4);
		circ_que.pop_front();
		circ_que.batch_emove(3);
		circ_que.push_back(5);
	}
	catch(const char* msg){
		cerr << msg << endl;
	}
	return 0;
}


















