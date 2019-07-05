#include<iostream>
//#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 510;
const int inf = 1000000000;

int n,m,start,en,G[maxn][maxn],weight[maxn];
int d[maxn],w[maxn],num[maxn];
bool vis[maxn];

void Dijkstra(int s) {

	fill(d,d+n,inf);
	d[s]=0;
	num[s]=1;
	w[s]=weight[s];
	for(int i=0; i<n; i++) {
		int u=-1,min=inf;
		for(int j=0; j<n; j++) {
			if(!vis[j]&&d[j]<min) {
				u=j;
				min=d[j];
			}
		}
		if(u==-1) break;
		vis[u] = true;
		for(int v=0; v<n; v++) {
			if(!vis[v] && G[u][v]!=inf) {
				if(d[v]>d[u]+G[u][v]) {
					d[v]=d[u]+G[u][v];
					w[v]=w[u]+weight[v];
					num[v]=num[u];
				} else if(d[v] == d[u]+G[u][v]) {
					if(w[v]<w[u]+weight[v]) {
						w[v]=w[u]+weight[v];
					}
					num[v]+=num[u];
				}
			}
		}
	}
}
int main() {
	cin>>n>>m>>start>>en;
	for(int i=0; i<n; i++) {
		cin>>weight[i];
	}
	int u,v;
	fill(G[0],G[0]+maxn*maxn,inf);
	for(int i=0; i<m; i++) {
		cin>>u>>v;
		cin>>G[u][v];
		G[v][u]=G[u][v];
	}
	Dijkstra(start);
	printf("%d %d\n",num[en],w[en]);
}

