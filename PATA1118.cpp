#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 10005
int father[maxn];

int find(int x){
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
	int fa=find(a);
	int fb=find(b);
	if(fa!=fb){
		father[fa]=fb;
	}
}

int maxIndex=-1;
int isRoot[maxn];

int main(){
	int N,Q,K,bird1,bird2;
	for(int i=0;i<maxn;i++) father[i]=i;
	cin>>N;
	for(int i=0;i<N;i++){
		scanf("%d%d",&K,&bird1);
		maxIndex=max(maxIndex,bird1);
		for(int j=1;j<K;j++){
			scanf("%d",&bird2);
			maxIndex=max(maxIndex,bird2);
			Union(bird1,bird2);
		}
	}
	for(int i=1;i<=maxIndex;i++){
		isRoot[find(i)]++;
	}
	int cnt=0;
	for(int i=1;i<=maxIndex;i++){
		if(isRoot[i]!=0) cnt++;
	}
	printf("%d %d\n",cnt,maxIndex);
	cin>>K;
	for(int i=0;i<K;i++){
		int a,b;
		cin>>a>>b;
		if(find(a)==find(b)) printf("Yes\n");
		else printf("No\n");
	}
}
