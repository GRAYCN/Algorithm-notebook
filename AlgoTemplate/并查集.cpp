//A1020
#include<iostream>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

const int maxn = 105;
int father[maxn];

int N,M;
void init(){
	for(int i=1;i<=N;i++)
		father[i]=i;
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

void Union(int a, int b){
	int fa=findFather(a);
	int fb=findFather(b);
	if(fa!=fb){
		father[fa]=fb;
	}
}

bool isRoot[maxn];

int main(){
	cin>>N>>M;
	init();
	for(int i=0;i<M;i++){
		int a,b;
		cin>>a>>b;
		Union(a,b);
	}
	int cnt;
	for(int i=1;i<=N;i++){
		if(father[i]==i){
			cnt++;
		}
	}
	cout<<cnt<<endl;
}
