//PATB1004
//��Ϊû������ѧ���ĳɼ���ͬ�����Կ��Խ��ɼ���Ϊѧ��������±�
//������������ַ�������һ�ַ���ͨ�������ַ�������ʵ���ַ��������ǲ���Ϊʲô��ʧ��
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
