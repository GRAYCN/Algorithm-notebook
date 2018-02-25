//A1072
// 要求：使得加油站到达所有居民的的最小距离尽可能短，但是必须保证所有的房屋都在
//其服务范围内
// 如果这样的点不止一个，那么输出到所有房屋平均距离最短的房屋
//如果还是不止一个，输出拥有最小下标的点 
// 26' 
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
#define INF 99999999
#define maxn 1015
int e[maxn][maxn];
bool vis[maxn];
int dis[maxn];
int N,M,K,Ds;
int globalMinIndex=-1;
double globalMaxMinDist=-1,minAvg=INF;
void Dijkstra(int s){
	fill(dis, dis+maxn, INF);
	fill(vis,vis+maxn,false);
	dis[s]=0;
	for (int i=1; i<=N+M; i++) {
		int u=-1,min=INF;
		for (int j=1; j<=N+M; j++) {
			if(!vis[j] && dis[j]<min){
				u=j;
				min=dis[j];
			}
		}
		if(u==-1) break;
		vis[u]=true;
		for (int v=1; v<=N+M; v++) {
			if (!vis[v] && e[u][v]!=INF) {
				if (dis[v]>dis[u]+e[u][v]) {
					dis[v] = dis[u]+e[u][v];
				}
			}
		}
	}
}

void find(int& minDis,int& maxDis, double& avg){
	double sum=0;
	for(int i=1;i<=N;i++){
		sum+=dis[i];
		if(dis[i]>maxDis){
			maxDis=dis[i];
		}
		if(dis[i]<minDis){
			minDis=dis[i];
		}
	}
	avg=sum/N;
}

int main() {
	cin>>N>>M>>K>>Ds;
	fill(e[0], e[0]+maxn*maxn, INF);
	for (int i=0; i<K; i++) {
		string str_a,str_b;
		int a,b,distance;
		cin>>str_a>>str_b>>distance;
		a= str_a[0]=='G' ? str_a[1]-'0'+N: str_a[0]-'0';
		b= str_b[0]=='G' ? str_b[1]-'0'+N: str_b[0]-'0';
		e[a][b]=e[b][a]=distance;
	}

	for(int i=N+1;i <=(N+M);i++){
		
		Dijkstra(i);
		int minDis=INF,maxDis=-1;
		double avg=0;
		find(minDis,maxDis,avg);
		if(maxDis>Ds) continue;
		if(minDis>globalMaxMinDist){
			globalMaxMinDist=minDis;
			globalMinIndex=i;
			minAvg=avg;
		}else if(minDis==globalMaxMinDist && avg<minAvg){
			globalMinIndex=i;
			minAvg=avg;
		}
	}
	if(globalMinIndex==-1) printf("No Solution");
	else{
		printf("G%d\n",globalMinIndex-N);
		printf("%.1f %.1f",globalMaxMinDist,minAvg);
	}
	return 0;
}
