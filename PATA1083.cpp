#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct Student{
	char name[12];
	char id[12];
	int grade;
}stu[102];

int cmp(Student a,Student b){
	return a.grade>b.grade;
}

int N;
int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>stu[i].name>>stu[i].id>>stu[i].grade;
	} 
	int min,max;
	cin>>min>>max;
	sort(stu,stu+N,cmp);
	int count=0;
	for(int i=0;i<N;i++){
		if(stu[i].grade>=min && stu[i].grade<=max){
			count++;
			cout<<stu[i].name<<" "<<stu[i].id<<endl;
		}
	}
	if(count==0)
		cout<<"NONE"<<endl;
}
