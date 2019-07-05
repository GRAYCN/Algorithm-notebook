//PATA1098
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<int> seq, ori,ins,heap_temp,heap;

bool flag=false;		//当flag为true时调出

void insertSort() {
	ins=seq;
	int i;
	for(i=2; i<=ins.size(); i++) {
		sort(ins.begin(),ins.begin()+i);
		if(ins==ori) {
			flag = true;
			break;
		}
	}
	if(flag==true) {
		cout<<"Insertion Sort"<<endl;
		//再进行下一轮循环
		sort(ins.begin(),ins.begin()+i+1);
		for(int j=0; j<ins.size(); j++) {
			cout<<ins[j];
			if(j!=ins.size()-1)
				cout<<" ";
		}
	}
}

void downAdjust(int low, int high) {
	int i=low,j=i*2+1;
	while(j<=high) {
		if(j+1<=high && heap[j+1]>heap[j]) {
			j=j+1;
		}
		if(heap[j]>heap[i]) {
			swap(heap[j],heap[i]);
			i=j;
			j=i*2+1;
		} else {
			break;
		}
	}
}

void createHeap(){
	int n = heap.size()-1;
	for(int i=(n-1)/2;i>=0;i--){
		downAdjust(i,n);
	}
}

void heapSort() {
	heap=seq;
	createHeap(); 
	int i;
	for(i=ins.size()-1; i>1; i--) {
		swap(heap[0],heap[i]);
		downAdjust(0,i-1);
		if(heap==ori) {
			flag=true;
			break;
		}
	}
	if(flag==true) {
		i--;
		swap(heap[0],heap[i]);
		downAdjust(0,i-1);
		cout<<"Heap Sort"<<endl;
		for(int j=0; j<heap.size(); j++) {
			cout<<heap[j];
			if(j!=heap.size()-1)
				cout<<" ";
		}
	}
}

int main() {
	cin>>N;
//	seq.resize(N);
	for(int i=0; i<N; i++) {
		int temp;
		cin>>temp;
		seq.push_back(temp);
	}
	for(int i=0; i<N; i++) {
		int temp;
		cin>>temp;
		ori.push_back(temp);
	}
	//先模拟插入排序，过程中检测是否和ori相同
	insertSort();
	//如果始终不相同，才会执行堆排序
	if(flag==false) {
		heapSort();
	}

}
