// 通过只交换0实现将数组顺序排序
//观察0的位置，
//1.如果0不在0号位置，就将0所在位置的下标的数字所在的位置与0所在的位置交换
//2.如果0已经归位，那么就将0和遍历数组中第一个不在本位置的数字交换
//line39 有些不能理解了 
#include<iostream>
#include<algorithm>
#define maxn 100005
using namespace std;

int pos[maxn];		//记录数字i所处的位置
int main() {
	int N;
	cin>>N;
	int left=N-1;		//记录除0以外还没有归位的个数
	for(int i=0; i<N; i++) {
		int num;
		cin>>num;
		pos[num]=i;
		if(num==i && num!=0) {
			left--;
		}
	}

	//开始循环遍历，直到left为0为止
	int count=0;
	int k=0;		//第一个不在本位上的数字
	while(left) {
		//如果0不在本位上，交换pos[pos[0]]和pos[0]
		while(pos[0]!=0) {
			swap(pos[pos[0]],pos[0]);
			count++;
			left--;
		}

		//如果0还在本位上，那么寻找从左到右第一个不在本位上的数字和0交换
		if(pos[0]==0) {
			while(k<N-1) {
				k++;
				if(k==N-1)
					break;
				else if(k!=pos[k]) {
					swap(pos[k],pos[0]);
					count++;
					break;
				}
			}
		}
	}
	cout<<count;
}

