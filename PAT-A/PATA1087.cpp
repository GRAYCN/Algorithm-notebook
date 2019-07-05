#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
const int maxn = 210;
const int inf = 1000000000;
int G[maxn][maxn];
bool vis[maxn];
int weight[maxn];			//点权即快乐度
int dis[maxn];
int N,K;
//string intToStr[maxn];
map<int,string> intToStr;
map<string,int> strToInt;
string start,en;
vector<int> pre[maxn], path, tempPath;
int maxHappy=-1,maxAvg=-1;
int num[maxn];

void dijkstra(int s) {
	fill(dis,dis+maxn,inf);
	num[s]=1;
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
			if(!vis[v]&&G[u][v]!=inf) {
				if(dis[v]>dis[u]+G[u][v]) {
					dis[v]=dis[u]+G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
					num[v]=num[u];
				} else if(dis[v]
				==
					dis[u]+G[u][v]) {
						pre[v].push_back(u);
						num[v]+=num[u]; 
				}
			}
		}
	}
}

void DFS(int index) {
	if(index
		==
		0) {
			tempPath.push_back(index);
			//从后向前遍历点权
			int happy=0,avg;
			for(int i=tempPath.size()-1; i>=0; i--) {
				int id=tempPath[i];
				happy+=weight[id];
			}
			avg=happy/(tempPath.size()-1);
			if(happy>maxHappy) {
				maxHappy=happy;
				path=tempPath;
				maxAvg=avg;
			} else if(happy
				==
				maxHappy&&avg>maxAvg){
					maxAvg=avg;
					path=tempPath;
			}
			tempPath.pop_back();
	}
	tempPath.push_back(index);
	for(int i=0; i<pre[index].size(); i++) {
		DFS(pre[index][i]);
	}
	tempPath.pop_back();

}

int main() {
	fill(G[0],G[0]+maxn*maxn,inf);
	cin>>N>>K;
	cin>>start;
	//处理起点和终点，将起点设置为0
	intToStr[0]=start;
	strToInt[start]=0;
	en="ROM";
	for(int i=1; i<=N-1; i++) {
		string name;
		int happy;
		cin>>name>>happy;
		intToStr[i]=name;
		strToInt[name]=i;
		//记录终点的下标
		//		if(name=="ROM") {
		//			en=i;
		//		}
		weight[i]=happy;		//点权
	}
	for(int i=0; i<K; i++) {
		string from,to;
		int distance;
		cin>>from>>to>>distance;
		G[strToInt[from]][strToInt[to]]=distance;
		G[strToInt[to]][strToInt[from]]=distance;
	}
	dijkstra(0);
	fill(vis,vis+maxn,false);
	int last=strToInt[en];
	DFS(last);
	printf("%d %d %d %d\n",num[last],dis[last],maxHappy,maxAvg);
	for(int i=path.size()-1;i>=0;i--){
		int id=path[i];
		cout<<intToStr[id];
		if(i>0) cout<<"->";
	}
}
