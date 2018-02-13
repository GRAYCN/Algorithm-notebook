//PATA1122
//24' awkward
#include<iostream>
#define maxn 210
using namespace std;
int a[maxn];
int e[maxn][maxn];
int visit[maxn];
int main(){
	int N,M,K;
	cin>>N>>M;
	for(int i=0;i<M;i++){
		int u,v;
		cin>>u>>v;
		e[u][v]=e[v][u]=1;
	}
	cin>>K;
	for(int i=0;i<K;i++){

		int k;
		cin>>k;
		fill(visit+1,visit+N+1,1);
		for(int j=1;j<=k;j++){
			cin>>a[j];
		}
		if(a[1]!=a[k]){
			printf("NO\n");
			continue;
		}else{
			bool flag=true;
			for(int i=1;i<k;i++){
				if(!e[a[i]][a[i+1]]){
					printf("NO\n");
					flag=false;
					break;
				}else{
					visit[a[i]]--;
				}
			}
			if(!flag) continue;
			for(int i=1;i<k;i++){
				if(visit[i]!=0){
					printf("NO\n");
					flag=false;
					break;	
				}
			}
			if(!flag) continue;
			printf("YES\n");
		}
	}
}
