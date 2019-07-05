//并查集学习
#include<iostream>
#include<algorithm>
#define maxn 110 
using namespace std;
int father[maxn];
bool isRoot[maxn];

for(int i=1;i<=N;i++){
	father[i]=i;
} 

int findFather(int x){
	int a=x;
	while(x!=father(x)){
		x=father(x);
	}
	while(a!=father(a)){
		int z=a;
		a=father(a);
		father(z)=x;
	}
	return x;
}

void Union(int a, int b){
	int faA=findFather(a);
	int faB=findFather(b);
	if(faA!=faB){
		father[faA]=faB;
	}
}

void init(int n){
	
}
int main(){
		
}
