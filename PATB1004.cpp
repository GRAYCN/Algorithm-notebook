//PATB1004
//因为没有两个学生的成绩相同，所以可以将成绩作为学生数组的下标
//本题采用了两种方案，第一种方案通过操作字符数组来实现字符串，但是不解为什么会失败
#include <stdio.h>
#include <iostream>
#define maxn 105
#include <string>
using namespace std;
struct stu {
//	char Name[12];
//	char Sno[12];
	string Name;
	string Sno;
} gra[maxn];

int n;
int main() {
	scanf("%d",&n);
//	char name[12],sno[12];
	string name,sno;
	int grade;
	for(int i=0; i<n; i++) {
//		scanf("%s%s%d",name,sno,&grade);
		cin>>name>>sno>>grade;
		gra[grade].Name=name;
		gra[grade].Sno=sno;
	}
	for(int i=maxn-1; i>=0; i--) {
		if(gra[i].Name!="") {
//			printf("%s%s\n",gra[i].Name,gra[i].Sno);
			cout<<gra[i].Name<<" "<<gra[i].Sno<<endl;
			break;
		}
	}
	for(int i=0; i<maxn; i++) {
		if(gra[i].Name!="") {
//			printf("%s%s\n",gra[i].Name,gra[i].Sno);
			cout<<gra[i].Name<<" "<<gra[i].Sno<<endl;
			break;
		}
	}
	return 0;
}
