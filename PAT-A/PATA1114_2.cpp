//PATA1114_2
//UFS
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
#define maxn 1005
#define maxm 10005
struct People{
	int id,fid,mid,num,area;
	int cid[8];
}peo[maxn];

struct Answer{
	int id;
	double num,area;
	int people;
	bool flag;
}ans[maxm];

bool visit[maxm];
int father[maxm];

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

bool cmp(Answer a,Answer b){
	if(a.area!=b.area) return a.area>b.area;
	else return a.id<b.id;
}

void Union(int a,int b){
	int fa=find(a);
	int fb=find(b);
	if(fa>fb){
		//fb=father[fa];
		father[fa]=fb;
	}else if(fa<fb){
		//fa=father[fb];
		father[fb]=fa;
	}
}

int main(){
	int N,k;
	for(int i=0;i<maxm;i++) father[i]=i;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>peo[i].id>>peo[i].fid>>peo[i].mid>>k;
		visit[peo[i].id]=true;
		if(peo[i].fid!=-1){
			visit[peo[i].fid]=true;
			Union(peo[i].id,peo[i].fid);
		}
		if(peo[i].mid!=-1){
			visit[peo[i].mid]=true;
			Union(peo[i].id,peo[i].mid);
		}
		for(int j=0;j<k;j++){
			cin>>peo[i].cid[j];
			visit[peo[i].cid[j]]=true;
			Union(peo[i].id,peo[i].cid[j]);
		}
		cin>>peo[i].num>>peo[i].area;
	}

	for(int i=0;i<N;i++){
		if(visit[peo[i].id]){
			int id=find(peo[i].id);
			ans[id].id=id;
			//			ans[id].people++;
			ans[id].num+=peo[i].num;
			ans[id].area+=peo[i].area;
			ans[id].flag=true;
		}
	}
	for(int i=0;i<maxm;i++){
		if(visit[i]){
			int id=find(i);
			ans[id].people++;
		}
	}

	int cnt=0;
	for(int i=0;i<maxm;i++){
		if(ans[i].flag==true){
			cnt++;
			ans[i].num=(float)(ans[i].num/ans[i].people);
			ans[i].area=(float)(ans[i].area/ans[i].people);
		}
	}
	sort(ans,ans+maxm,cmp);
	cout<<cnt<<endl;
	for(int i=0;i<cnt;i++){
		printf("%04d %d %.3f %.3f\n",ans[i].id,ans[i].people,ans[i].num,ans[i].area);
	}	
}
