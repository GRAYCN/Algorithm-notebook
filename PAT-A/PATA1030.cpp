//PATA1030
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int inf = 100000000;
const int maxn = 510;

int N,M,S,D;
int G[maxn][maxn];
vector<int> pre[maxn];
bool vis[maxn];
int cost[maxn][maxn];
int dis[maxn];
vector<int> path;
vector<int> tempPath;
int minValue=inf;

void DFS(int index) {
	if(index == S) {
		tempPath.push_back(index);
		int value=0;
		for(int i=tempPath.size()-1;i>0;i--){
			int a=tempPath[i],b=tempPath[i-1];
			value+=cost[a][b];
		}
		if(value<minValue){
			minValue=value;
			path=tempPath;
		}
		tempPath.pop_back();
		return;
	}
	//对index的邻边进行递归
	tempPath.push_back(index);
	for(int i=0; i<pre[index].size(); i++) {
		int nextt=pre[index][i];
		if(!vis[nextt] && G[index][nextt]!=inf) {
			DFS(nextt);
		}
	}
	tempPath.pop_back();
}

void Dijkstra(int s) {
	fill(dis,dis+maxn,inf);
	dis[s]=0;
	for(int i=0; i<N; i++) {
		int u=-1,min=inf;
		for(int j=0; j<N; j++) {
			if(!vis[j] && dis[j]<min) {
				u=j;
				min=dis[j];
			}
		}
		if(u==-1) break;
		vis[u]=true;
		for(int v=0; v<N; v++) {
			if(!vis[v] && G[u][v]!=inf) {
				if(dis[v]>dis[u]+G[u][v]) {
					dis[v]=dis[u]+G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				} else if(dis[v] == dis[u]+G[u][v]) {
					pre[v].push_back(u);
				}
			}
		}
	}
//	fill(vis,vis+N,false);
	DFS(D);
}

int main() {
	cin>>N>>M>>S>>D;
	int a,b,d,c;
	fill(G[0],G[0]+maxn*maxn,inf);
	for(int i=0; i<M; i++) {
		cin>>a>>b>>d>>c;
		G[a][b]=d;
		G[b][a]=d;
		cost[a][b]=c;
		cost[b][a]=c;
	}
	Dijkstra(S);
	for(int i=path.size()-1;i>=0;i--){
		if(i!=path.size()-1) cout<<" ";
		cout<<path[i];
	}
	cout<<" "<<dis[D]<<" "<<minValue;
} 
