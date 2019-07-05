//PATB1028
//很简单的模拟题，建立三个结构体变量 man,old,young，在循环遍历的过程中给old和young赋值
//如果输入的日期字符串大于2014/09/06或者小于1814/09/06，就continue，在过程中记录合理的日期。
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
