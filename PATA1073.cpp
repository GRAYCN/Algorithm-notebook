//PATA1073
#include<cstdio> 
#include<cstring>
#include<iostream>
#define maxn 10005
using namespace std;
char a[maxn];
int main(){
	scanf("%s",a);
	int len = strlen(a);
	//�Ƚ�������� 
	if(a[0]=='-')
		cout<<a[0];
	//�ҵ�E������λ��pos
	int pos=0;
	while(a[pos]!='E')
		pos++;
	//����exp�Ĵ�С 
	int exp=0;
	for(int i=pos+2;i<len;i++){
		exp=10*exp+(a[i]-'0');
	}
	//���exp�Ǹ���
	if(a[pos+1]=='-'){
		cout<<"0.";
		for(int i=0;i<exp-1;i++) cout<<'0';
		for(int i=1;i<pos;i++){
			if(a[i]=='.') continue;
			cout<<a[i];
		}
	} else{		//��������� 
		//�ȴ��±�Ϊ1����ʼ�����ȥ��'.' 
		for(int i=1;i<pos;i++){
			if(a[i]=='.') continue;
			cout<<a[i];
			//����'.'��λ��
			if(i==exp+2 && exp<pos-3){
				cout<<'.';
			} 
		} 
		for(int i=0;i<exp-(pos-3);i++){
			cout<<'0';
		}
	}
}
