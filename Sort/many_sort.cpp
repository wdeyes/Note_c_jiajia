#include <iostream>
#include <vector>
using namespace std;

//冒泡  O(time)=n^2  属于稳定排序
// 最好比较n次, 最坏比较 n^2/2 次，交换 n^2/2 次
void bubble_sort(vector<int> &nums){
	int len = nums.size();
	bool nosort=true;
	for(int i=0; i<=len-2 && nosort; ++i){
		nosort=false;//先改成 false，后面只要有交换就改为 true
		for(int j=len-2; j>=i; --j){
			if(nums[j]>nums[j+1]){
				swap(nums[j], nums[j+1]);
				nosort=true;
			}
		}
	}
}

//简单选择排序  n^2   属于稳定排序
//用买股票来说，冒泡排序就是不断的买进卖出，选择排序就是长期的观察，在最佳时机卖出。
//看他们各自的代码，冒泡排序主要花费在比较、交换，选择排序主要花费在比较，虽然都是n^2，但是选择排序要优些。
// 最好比较 n^2/2 次，交换0次，最坏比较 n^2/2 次，交换 n 次
void simple_selection_sort(vector<int> &nums){
	int len=nums.size();
	for(int i=0; i<len; ++i){
		int min=i;
		for(int j=i+1; j<len; ++j){
			if(nums[j]<nums[min])
				min=j;
		}
		if(i!=min)
			swap(nums[i], nums[min]);
	}
}

//直接插入排序  n^2   稳定排序
//就像玩扑克牌，遇到不符合顺序的，插入到合适的位置,插入的时候用到了前面排好的顺序
//虽然也是n^2，但是比冒泡和选择好些
//最好比较 n 次，最坏比较 n^2/2，移动 n^2/2。好坏一平均就是 n^2/4。
void straight_insertion_sort(vector<int> &nums){
	int len=nums.size();
	for(int i=1; i<len; ++i){
		if(nums[i]<nums[i-1]){
			int temp=nums[i];
			int j=i-1;
			for(; j>=0&&nums[j]>temp; --j){
				nums[j+1]=nums[j]; //后移
			}
			nums[j+1]=temp;//nums[j]是第一个<=temp 的数字，这里插入
		}
	}
}

//希尔排序，开拓者，在直接插入排序的基础上改进，改变了排序算法只能 n^2 的观点
// 以不同的距离进行插入排序
// 时间在 n^2 以下，因为是跳跃的插入，属于不稳定排序
void shell_sort(vector<int> &nums){
	int len = nums.size();
	int d = len;
	do{
		d = d/3+1;
		for(int i=d; i<len; ++i){
			if(nums[i] < nums[i-d]){
				int temp = nums[i];
				int j=i-d;
				for(; j>=0&&nums[j]>temp; j-=d)
					nums[j+d]=nums[j];
				nums[j+d] = temp;
			}
		}	
	}while(d>1);
}

//堆排序，n*logn，比较和交换时跳跃性的，因此属于不稳定排序
//思路是：最大堆的堆顶依次放到后面
void heap_adjust(vector<int> &nums, int start, int end){
	int temp = nums[start];
	for(int j=2*start+1; j<=end; j=j*2+1){
		if(j<end && nums[j]<nums[j+1])//j变成两个孩子结点中大的
			++j;
		if(nums[j]<=temp)//两个孩子都小于temp，则提前跳出，temp插入到这里
			break;
		nums[start]=nums[j];
		start = j;
	}
	nums[start]=temp;
}
void heap_sort(vector<int> &nums){
	int len=nums.size();
	//这里直接使用现成的 make_heap 函数将数组构成最大堆
	make_heap(nums.begin(), nums.end());
	for(int i=len-1; i>0; --i){
		//最大堆的堆顶依次放到后面
		swap(nums[0], nums[i]);
		//使前面的变成堆，使用参考大话数据结构的函数，复杂度为logn，它只有堆顶不符合最大堆
		//make_heap(nums.begin(), nums.begin()+ i-1 );
		heap_adjust(nums, 0, i-1);
	}
}

//归并排序，稳定排序，n*logn
//递归实现
void merge(vector<int> &nums, int start, int m, int end){
	vector<int> copy = nums;
	int i=start, j=m+1, k=start;
	for(; i<=m&&j<=end; ){
		if(copy[i]<copy[j])
			nums[k++]=copy[i++];
		else
			nums[k++]=copy[j++];
	}
	for(; i<=m; )
		nums[k++]=copy[i++];
	for(; j<=end; )
		nums[k++]=copy[j++];
}
void core(vector<int> &nums, int start, int end){
	if(start==end)
		return;
	int m = (start+end)/2;
	core(nums, start, m);
	core(nums, m+1, end);
	merge(nums, start, m, end);
}
void merging_sort_recursion(vector<int> &nums){
	core(nums, 0, nums.size()-1);
}
//循环实现
void merge_sort(vector<int> &nums){

}


//快速排序见剑指offer的面试题11


int main(int argc, char const *argv[])
{
	vector<int> nums={3,2,1,9,8,7,6,5,4};
	for(auto val:nums)
		cout << val << " ";
	cout << endl; 

	merging_sort(nums);
	cout << "after sort: " << endl;
	for(auto val:nums)
		cout << val << " ";
	cout << endl; 

	return 0;
}	