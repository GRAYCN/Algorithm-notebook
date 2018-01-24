#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct Student{
	int id;
	int ge;
	int gi;
	int sum;
	int pri[6];
}stu[40005];

void init(){
	for(int i=0;i<N;i++){
		stu[i].id=i; 
	}
} 

int cmp(Student a,Student b){
	if(a.sum!=b.sum) return a.sum>b.sum;
	else return a.ge>b.ge;
}
int N,M,K;
int school[105];
int main(){
	cin>>N>>M>>K;
	for(int i=0;i<M;i++){
		cin>>school[i];		
	}
	for(int i=0;i<N;i++){
		cin>>stu[i].ge>>stu[i].gi;
		for(int j=0;j<k;j++){
			cin>>stu[i].pri[j];
		}
	}
	//计算学生总分
	for(int i=0;i<N;i++){
		stu[i].sum=stu[i].ge+stu[i].gi;
	} 
	//对学生进排序
	sort(stu,stu+N,cmp);
	
	 
} 
