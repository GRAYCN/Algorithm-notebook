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
	//先将符号输出 
	if(a[0]=='-')
		cout<<a[0];
	//找到E所处的位置pos
	int pos=0;
	while(a[pos]!='E')
		pos++;
	//计算exp的大小 
	int exp=0;
	for(int i=pos+2;i<len;i++){
		exp=10*exp+(a[i]-'0');
	}
	//如果exp是负数
	if(a[pos+1]=='-'){
		cout<<"0.";
		for(int i=0;i<exp-1;i++) cout<<'0';
		for(int i=1;i<pos;i++){
			if(a[i]=='.') continue;
			cout<<a[i];
		}
	} else{		//如果是正数 
		//先从下标为1处开始输出，去掉'.' 
		for(int i=1;i<pos;i++){
			if(a[i]=='.') continue;
			cout<<a[i];
			//考虑'.'的位置
			if(i==exp+2 && exp<pos-3){
				cout<<'.';
			} 
		} 
		for(int i=0;i<exp-(pos-3);i++){
			cout<<'0';
		}
	}
}
