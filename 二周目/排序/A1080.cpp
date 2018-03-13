//A1080 26'
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;
#define maxn 40005
#define maxm 105
vector<int> v[maxn];

struct Node{
	int GE,GI,GF;
	int id;
	int want[10];
	int rank;
}peo[maxn];
int quote[maxm];
int lastId[maxn];

int N,M,K;

int cmp(Node a, Node b){
	if(a.GF!=b.GF) return a.GF>b.GF;
	else return a.GE>b.GE;
}

int main(){
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0;i<M;i++){
		scanf("%d",&quote[i]);
	}
	for(int i=0;i<N;i++){
		scanf("%d%d",&peo[i].GE,&peo[i].GI);
		peo[i].id=i;
		peo[i].GF=peo[i].GE+peo[i].GI;
		for(int j=0;j<K;j++){
			scanf("%d",&peo[i].want[j]);
		}
	}
	sort(peo,peo+N,cmp);
	peo[0].rank=1;
	for(int i=1;i<N;i++){
		if(peo[i].GF==peo[i-1].GF && peo[i].GE==peo[i-1].GE){
			peo[i].rank=peo[i-1].rank;
		}else{
			peo[i].rank=i+1;
		}
	}
	fill(lastId,lastId+N,-1);
	for(int i=0;i<N;i++){
		for(int j=0;j<K;j++){
			if(quote[peo[i].want[j]]>0){
				quote[peo[i].want[j]]--;
				v[peo[i].want[j]].push_back(peo[i].id);
				lastId[peo[i].want[j]]=peo[i].id;
				break;
			}else if( quote[peo[i].want[j]]==0 && peo[i].rank==peo[ lastId[peo[i].want[j]] ].rank ){
				v[peo[i].want[j]].push_back(peo[i].id);
				lastId[peo[i].want[j]]=peo[i].id;
				break;
			}
		}
	}
	for(int i=0;i<M;i++){
		sort(v[i].begin(),v[i].end());
		for(int j=0;j<v[i].size();j++){
			printf("%d",v[i][j]);
			if (j!=v[i].size()-1)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
} 

/*
5 5 3
0 0 0 5 5
100 100 0 1 2
100 99 1 2 0
99 100 2 1 0
99 99 1 0 2
98 98 2 0 1
*/ 
