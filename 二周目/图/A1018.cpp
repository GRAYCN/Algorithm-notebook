#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define INF 99999999
#define maxn 510
int e[maxn][maxn];
bool vis[maxn];
int dis[maxn];
int maxSum=-1;
vector<int> pre[maxn], path, tempPath;
int Cmax,N,Sp,M;
int C[maxn];
int minOut=INF,minback=INF;

void Dijkstra(int s){
	fill(dis, dis+maxn, INF);
	dis[s]=0;
	for (int i=0; i<maxn; i++) {
		int u=-1,min=INF;
		for (int j=0; j<maxn; j++) {
			if(!vis[j] && dis[j]<min){
				u=j;
				min=dis[j];
			}
		}
		if(u==-1) break;
		vis[u]=true;
		for (int v=0; v<maxn; v++) {
			if (!vis[v] && e[u][v]!=INF) {
				if (dis[v]>dis[u]+e[u][v]) {
					dis[v] = dis[u]+e[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(dis[v]==dis[u]+e[u][v]){
					pre[v].push_back(u);
				}
			}
		}
	}
}
int cnt=0;
void DFS(int index){
	if(index==0){
		tempPath.push_back(index);
		int out=0;
		int back=0;
		for (int i = tempPath.size()-1; i>=0; i--) {
			int id = tempPath[i];
			if(C[id]>0){
				back+=C[id];
			}else if(C[id]<0){
				if(back>abs(C[id])){
					back-=abs(C[id]);
				}else{
					out+=abs(C[id])-back;
					back=0;
				}
			}	
		}
		if(out<minOut){
			minOut=out;
			minback=back;
			path=tempPath;
		}else if(out == minOut && back<minback){
			minback=back;
			path=tempPath;
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(index);
	for (int i=0; i<pre[index].size(); i++) {
		int id=pre[index][i];
		DFS(id);
	}
	tempPath.pop_back();
}

int main() {

	//	cin>>N>>M>>C1>>C2;
	cin>>Cmax>>N>>Sp>>M;
	fill(e[0], e[0]+maxn*maxn, INF);
	for (int i=1; i<=N; i++) {
		cin>>C[i];
		C[i] -= Cmax/2;
	}
	for (int i=0; i<M; i++) {
		int a,b,length;
		cin>>a>>b>>length;
		e[a][b]=e[b][a]=length;
	}
	Dijkstra(0);
	DFS(Sp);
	printf("%d ",minOut);
	cout<<"0";
	for (int i = path.size()-2; i>=0; i--) {
		int id = path[i];
		printf("->%d",id);
	}
	printf("% d",minback);
	return 0;
}
