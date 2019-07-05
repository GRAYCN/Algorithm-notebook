//PATA1114
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct People{
	int id,fid,mid,num,area;
	int cid[10];
}people[1005];

struct node{
	int id,people;
	double num,area;
	bool flag;		//wow
}ans[10000];

int father[10000];
bool visit[10000];

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
		father[fb]=fa;
	}
}

int cmp(node a,node b){
	if(a.area!=b.area) return a.area>b.area;
	else return a.id<b.id; 
}

int main(){
	int N,k,cnt=0;
	scanf("%d",&N);
	for(int i=0;i<10000;i++){
		father[i]=i;
	}
	for(int i=0;i<N;i++){
		scanf("%d%d%d%d",&people[i].id,&people[i].fid,&people[i].mid,&k);
		visit[people[i].id]=true;
		if(people[i].fid!=-1){
			visit[people[i].fid]=true;
			Union(people[i].fid,people[i].id);
		}
		if(people[i].mid!=-1){
			visit[people[i].mid]=true;
			Union(people[i].mid,people[i].id);
		}
		for(int j=0;j<k;j++){
			scanf("%d",&people[i].cid[j]);
			visit[people[i].cid[j]]=true;
			Union(people[i].cid[j],people[i].id);
		}  
		scanf("%d%d",&people[i].num,&people[i].area);
	}
	for(int i=0;i<N;i++){
		int id=find(people[i].id);
		ans[id].id=id;
		ans[id].num+=people[i].num;
		ans[id].area+=people[i].area;
		ans[id].flag=true;
	}
	for(int i=0;i<10000;i++){
		if(visit[i]){
			ans[find(i)].people++;
			if(ans[i].flag)
				cnt++;
		}
	}
	for(int i=0;i<10000;i++){
		if(ans[i].flag){
			ans[i].num=(double)(ans[i].num*1.0/ans[i].people);
			ans[i].area=(double)(ans[i].area*1.0/ans[i].people);
		}
	}
	sort(ans,ans+10000,cmp);
	printf("%d\n", cnt);
	for(int i = 0; i < cnt; i++)
		printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].people, ans[i].num, ans[i].area);
}
