//PATA1013
#include<iostream>
using namespace std;
#include<cstdio>
#include<cstring>
#define maxn 1005
int e[maxn][maxn];
int vis[maxn];
int N,M,K;
int query;
void DFS(int index) {
	if (index==query) {
		return;
	}
	vis[index]=true;
	for(int i=1; i<=N; i++) {
		if(e[i][index]==1 && !vis[i]) {
			DFS(i);
		}
	}
}

int main() {
	cin>>N>>M>>K;
	for(int i=0; i<M; i++) {
		int a,b;
		cin>>a>>b;
		e[a][b]=1;
		e[b][a]=1;
	}
	for(int i=0; i<K; i++) {

		cin>>query;
		int cnt=0;
		memset(vis,false,sizeof(vis));
		for(int i=1; i<=N; i++) {
			if(i!=query && vis[i]==false) {
				DFS(i);
				cnt++;
			}

		}
		cout<<cnt-1<<endl;
	}
}
