//A1062
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
#include <cstdio>
using namespace std;
#define maxn 100005

struct Node{
	int id;
	int Virtue_Grade,Talent_Grade,Total;
	int catagary;
	Node(){
		catagary=0;
	}
}peo[maxn];
int N,L,H;

bool cmp(Node a, Node b){
	if(a.catagary!=b.catagary){
		return a.catagary>b.catagary;
	}else if(a.Total!=b.Total){
		return a.Total>b.Total;
	}else if(a.Virtue_Grade!=b.Virtue_Grade){
		return a.Virtue_Grade>b.Virtue_Grade;
	}else return a.id<b.id;
}

int main(){
	scanf("%d%d%d",&N,&L,&H);
	int cnt=0;
	for(int i=0;i<N;i++){
		scanf("%d%d%d",&peo[i].id,&peo[i].Virtue_Grade,&peo[i].Talent_Grade);
		peo[i].Total=peo[i].Virtue_Grade+peo[i].Talent_Grade;
		if(peo[i].Virtue_Grade>=H && peo[i].Talent_Grade>=H){
			cnt++;
			peo[i].catagary=4;		//sages
		}else if(peo[i].Virtue_Grade>=H && peo[i].Talent_Grade>=L){
			cnt++;
			peo[i].catagary=3;		//noblemen
		}else if(peo[i].Virtue_Grade>=L && peo[i].Talent_Grade>=L && peo[i].Virtue_Grade>=peo[i].Talent_Grade){
			cnt++;
			peo[i].catagary=2;		//fool men
		}else if(peo[i].Virtue_Grade>=L && peo[i].Talent_Grade>=L){
			cnt++;
			peo[i].catagary=1;		//small man
		}
	}
	printf("%d\n",cnt);
	sort(peo,peo+N,cmp);	
	for(int i=0;i<cnt;i++){
		printf("%d %d %d\n",peo[i].id,peo[i].Virtue_Grade,peo[i].Talent_Grade);
	}
} 
