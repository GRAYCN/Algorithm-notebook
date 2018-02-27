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
int N,M,S,D;
int cost[maxn][maxn];
int minCost=INF;

void Dijkstra(int s){
	fill(dis, dis+maxn, INF);
	dis[s]=0;
	for (int i=0; i<N; i++) {
		int u=-1,min=INF;
		for (int j=0; j<N; j++) {
			if(!vis[j] && dis[j]<min){
				u=j;
				min=dis[j];
			}
		}
		if(u==-1) break;
		vis[u]=true;
		for (int v=0; v<N; v++) {
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
	if(index==S){
		tempPath.push_back(index);
		int tempCost=0;
		for (int i = tempPath.size()-1; i>0; i--) {
			int id1 = tempPath[i];
			int id2 = tempPath[i-1];
			tempCost+=cost[id1][id2];
		}
		if(minCost>tempCost){
			minCost=tempCost;
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
	cin>>N>>M>>S>>D;
	fill(e[0], e[0]+maxn*maxn, INF);
	for (int i=0; i<M; i++) {
		int a,b,distance,costt;		//can it work?
		cin>>a>>b>>distance>>costt;	
		e[a][b]=e[b][a]=distance;
		cost[a][b]=cost[b][a]=costt;
	}
	Dijkstra(0);
	DFS(D);
	for (int i = path.size()-1; i>=0; i--) {
		int id = path[i];
		printf("%d ",id);
	 } 
	printf("%d %d",dis[D],minCost);
	return 0;
}
