//得到27分
//PATA1018
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 505;
const int inf = 1000000000;
int Cmax,N,SP,M;
int weight[maxn];
int G[maxn][maxn];
bool vis[maxn];
int dis[maxn];
vector<int> pre[maxn],path,tempPath;
int minOut=inf;
int minBack=inf;

void DFS(int index) {
	if(index==0) {
		tempPath.push_back(0);
		int out=0,back=0;
		int sum=0;
		for(int i=tempPath.size()-1; i>0; i--) {
			sum+=weight[tempPath[i]];
		}
		if(weight[tempPath[0]]<0) {
			sum+=weight[tempPath[0]];
		}
		if (sum>=0) {
			out=0;
		} else {
			out=-sum;
		}
		//out=max(0,-sum);
		if(out<minOut) {
			minOut=out;
			path=tempPath;
			int sum=0;
			for(int i=tempPath.size()-1; i>=0; i--) {
				sum+=weight[tempPath[i]];
			}
			back=sum+out;
			minBack=back;
		} else if(out == minOut) {		//还需要比较back
			int sum=0;
			for(int i=tempPath.size()-1; i>=0; i--) {
				sum+=weight[tempPath[i]];
			}
			back=sum+out;
			if(back<minBack) {
				minBack=back;
				path=tempPath;
			}
		}
		tempPath.pop_back();
	}

	tempPath.push_back(index);
	for(int i=0; i<pre[index].size(); i++) {
		int nextt=pre[index][i];
		if(!vis[nextt] && G[index][nextt]!=inf)
			DFS(nextt);
	}
	tempPath.pop_back();
}

void Dijkstra(int s) {
	fill(dis,dis+maxn,inf);
	dis[s]=0;

	for(int i=0; i<=N; i++) {
		int u=-1,min=inf;
		for(int j=0; j<=N; j++) {
			if(!vis[j] && dis[j]<min) {
				u=j;
				min=dis[j];
			}
		}
		if(u==-1) break;
		vis[u]=true;
		for(int v=0; v<=N; v++) {
			if(!vis[v] && G[u][v]!=inf) {
				if(dis[v]>dis[u]+G[u][v]) {
					dis[v]=dis[u]+G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				} else if(dis[v]==dis[u]+G[u][v]) {
					pre[v].push_back(u);
				}
			}
		}
	}
	fill(vis,vis+maxn,false);
	DFS(SP);
}

int main() {
	cin>>Cmax>>N>>SP>>M;
	fill(G[0],G[0]+maxn*maxn,inf);
	for(int i=1; i<=N; i++) {
		cin>>weight[i];
		weight[i]-=Cmax/2;		//预处理
	}
	for(int i=0; i<M; i++) {
		int a,b,t;
		cin>>a>>b>>t;
		G[a][b]=t;
		G[b][a]=t;
	}
	Dijkstra(0);
	cout<<minOut<<" ";
	for (int i=path.size()-1; i>=0; i--) {
		if (i!=path.size()-1) {
			cout<<"->";
		}
		cout<<path[i];
	}
	cout<<" "<<minBack<<endl;
}
