//问题秒速，设计一个类ClosetStorage，实现三个函数
// insert(item) 插入一个元素，如果存在则不操作 
// delete（item）删除一个元素，如果没有则不操作
// getClosest() 返回最接近的一对元素，如果存在多对，则任意返回一对

#include <iostream>
#include <set>
using namespace std;


class ClosetStorage{
public:
	ClosetStorage(){}
	//插入
	void insert(int item){
		if(m_data.find(item)==m_data.end())
			m_data.insert(item);
	}
	//删除
	void Delete(int item){
		if(m_data.find(item)!=m_data.end()){
			auto it = m_data.find(item);
			m_data.erase(it);
		}
	}
	//得到最接近的
	pair<int,int> getClosest(){
		if(m_data.size()<2)
			throw "data is not enough";

		auto it = m_data.begin();
		auto it_next = m_data.begin();
		++it_next;
		pair<int,int> ret;
		ret.first=*it;
		ret.second=*it_next;	
		while(it_next!=m_data.end()){
			if( abs(*it-*it_next) < abs(ret.first-ret.second) ){
				ret.first=*it;
				ret.second=*it_next;
			}
			++it;
			++it_next;
		}
		return ret;
	}
	//打印m_data
	void Print(){
		for(auto val:m_data)
			cout << val << " ";
		cout << endl;
	}

private:
	set<int> m_data;
};



int main(int argc, char const *argv[])
{
	ClosetStorage data;
	data.insert(1);
	data.insert(100);
	data.insert(2);
	data.insert(5);
	data.insert(7);
	data.insert(1);
	data.Delete(1);

	data.Print();
	pair<int,int> close = data.getClosest();
	cout << close.first << " " << close.second << endl;
	return 0;
}







