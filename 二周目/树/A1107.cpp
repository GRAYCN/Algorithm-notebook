//A1107
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std; 
#define maxn 1005
int hobby[maxn];
int father[maxn];
//int isRoot[maxn];
int peopleNumber[maxn];
int N;

void init(){
	for(int i=1;i<=N;i++){
		father[i]=i;
	}
}

int findFather(int x){
	int a=x;
	while(x!=father[x]){
		x=father[x];
	}
	while(a!=father[a]){
		int z=a;
		a=father[a];
		father[z]=x;
	}
	return x;
}

void Union(int a,int b){
	int fa=findFather(a);
	int fb=findFather(b);
	if(fa!=fb){
		//fa=father[fb];
		father[fa]=fb;
	}
}

int cmp(int a,int b){
	return a>b;
}

int main(){
	cin>>N;
	init();
	for(int i=1;i<=N;i++){
		int num,hobby_id;
		scanf("%d:",&num);
		for(int j=0;j<num;j++){
			cin>>hobby_id;
			if(hobby[hobby_id]==0){
				hobby[hobby_id]=i;
			}
			Union(findFather(hobby[hobby_id]),i);		//’‚¿Ô «findFather
		}
	}
	int cnt=0;
	for(int i=1;i<=N;i++){
		if(i==findFather(i)){
			cnt++;
		}
		peopleNumber[findFather(i)]++;
	}
	sort(peopleNumber+1,peopleNumber+1+N,cmp);
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++){
		cout<<peopleNumber[i];
		if(i!=cnt) cout<<" ";
	}
} 
