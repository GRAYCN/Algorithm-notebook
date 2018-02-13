//26分 
//PATA1072
#include<iostream>
#include<algorithm>
#include<string>
#include<cctype>
using namespace std;
const int maxn = 1020;
const int inf = 1000000000;
int G[maxn][maxn];
bool vis[maxn];
int dis[maxn];
//N  居民住宅数 M 加油站的候选站点 K 路径数目 Ds 服务范围（到加油站的最短距离小于等于Ds）
int N,M,K,Ds;
int ans=-1;			//选址的下标 N+1-N+M
int maxMinDis=-1;
double minAvg=inf;

void Dijkstra(int s){
	dis[s]=0;
	for(int i=1;i<=M+N;i++){
		int u=-1,min=inf;
		for(int j=1;j<=M+N;j++){
			if(!vis[j] && dis[j]<min){
				u=j;
				min=dis[j];
			}
		}
		if(u==-1) break;
		vis[u]= true;
		for(int v=1;v<=M+N;v++){
			if(!vis[v]&&G[u][v]!=inf){
				if(dis[v]>dis[u]+G[u][v]){
					dis[v]=dis[u]+G[u][v]; 
				}
			}
		}
	}
}

int main() {
	cin>>N>>M>>K>>Ds;
	fill(G[0],G[0]+maxn*maxn,inf);
	string a,b;
	int c,d,distance;
	for(int i=0; i<K; i++) {
		cin>>a>>b>>distance;
		//分别处理住宅区和加油站 住宅区 1-N 加油站 N+1-N+M
		if(isdigit(a[0])) c=a[0]-'0';
		else c=a[1]-'0'+N;
		if(isdigit(b[0])) d=b[0]-'0';
		else d=b[1]-'0'+N;
		G[c][d]=G[d][c]=distance;
	}
	//开始从N+1到N+M遍历使用Dij算法
	for(int i=N+1; i<=N+M; i++) {
		//初始化
		fill(vis,vis+maxn,false);
		fill(dis,dis+maxn,inf);
		Dijkstra(i);
		//找到最近居民点中的最小值，并且过程中对dis求和
		int minDis=inf,maxDis=-1;
		double sum=0;
		for(int j=1; j<=N; j++) {
			if(dis[j]<minDis) {
				minDis=dis[j];
			}
			if(dis[j]>maxDis){
				maxDis=dis[j];
			}
			sum+=dis[j];
		}
		if (maxDis>Ds)
		{
			continue;
		}
		double avg=sum/N;
		if(minDis>maxMinDis) {
			maxMinDis=minDis;
			ans=i;
			minAvg=avg;
		} else if(minDis
			==
			maxMinDis && avg<minAvg) {
				minAvg=avg;
				ans=i;
		}
	}

	if(ans
		==
		-1){
			cout<<"No Solution"<<endl;
	}else{
		cout<<"G"<<ans-N<<endl;
		printf("%.1f %.1f",(float)maxMinDis,minAvg);
	}
}
