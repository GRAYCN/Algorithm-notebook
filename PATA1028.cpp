//未完待续 

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct Student {
	int id;
	char name[10];
	int grade;
} stu[100005];
int n,c;
int cmp(Student a,Student b) {
	//c==1,对id升序排列
	if(c==1) {
		return a.id<b.id;
	}
	//c==2，对name非降序排列
	if(c==2) {
		int s=strcmp(a.name,b.name);
		if(s!=0) return s<0;
		else return a.id<b.id;
	}
	//c== 3 对grade非降序排列
	if(c==3) {
		if(a.grade!=b.grade) return a.grade<b.grade;
		else return a.id<b.id;
	}
}
int main() {
	scanf("%d%d",&n,&c);
	for(int i=0; i<n; i++) {
		scanf("%d%s%d",&stu[i].id,stu[i].name,&stu[i].grade);
//		cin>>stu[i].id>>stu[i].name>>stu[i].grade;
	}
	sort(stu,stu+n,cmp);
	for(int i=0; i<n; i++) {
		printf("%06d %s %d\n",stu[i].id,stu[i].name,stu[i].grade);
	}
}
