//PATB1028
//�ܼ򵥵�ģ���⣬���������ṹ����� man,old,young����ѭ�������Ĺ����и�old��young��ֵ
//�������������ַ�������2014/09/06����С��1814/09/06����continue���ڹ����м�¼��������ڡ�
#include <stdio.h>
#include <iostream> 
#include <string>
using namespace std;
#define maxn 10005
#define first "1814/09/06"
#define latest "2014/09/06"
struct people{
	string name;
	string birth;
}man,old,young; 
int N;
int main(){
	int count=0;
	scanf("%d",&N);
	old.birth="2014/09/06";
	young.birth="1814/09/06"; 
	for(int i=0;i<N;i++){
		cin>>man.name>>man.birth;
		if(man.birth>first && man.birth<latest){
			count++;
			if(man.birth>old.birth){
				old.birth=man.birth;
				old.name=man.name;
			}
			if(man.birth<young.birth){
				young.birth=man.birth;
				young.name=man.name;
			}
		}
	}
	cout<<count<<" "<<old.name<<" "<<young.name;
	return 0;
} 
