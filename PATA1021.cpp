//有一个测试点超时，可以参考算法笔记上的解析和柳婼给出的解题思路 
//still wrong
//PATA1021
#include<iostream>
#include<vector>
#define maxn 10005
#include<cstring>
#include<cstdio>
#include<algorithm>
#include <set>
using namespace std;
vector<int> Adj[maxn];
//set<int> ans;
int depthh[maxn];
bool vis[maxn];
int N;
int maxDepth=-1;
int globalMaxDepth;
int DFS(int index,int depth) {
	vis[index]=true;
	if(depth>maxDepth) {
		maxDepth=depth;
	}
	for(int i=0; i<Adj[index].size(); i++) {
		int j=Adj[index][i];
		if(!vis[j]) {
			DFS(j,depth+1);
		}
	}
	return maxDepth;
}

int main() {
	scanf("%d",&N);
	int a,b;
	for(int i=0; i<N-1; i++) {
		scanf("%d%d",&a,&b);
//		cin>>a>>b;
		Adj[a].push_back(b);
		Adj[b].push_back(a);
	}
	//采用深度优先搜素遍历，找最大深度
	int cnt=0;
	for(int i=1;i<=N;i++){
		if(!vis[i]){
			cnt++;
			DFS(i,1);
		}
	}
	if(cnt>1) {
		printf("Error: %d components\n",cnt);
		return 0;
	}
	for(int i=1; i<=N; i++) {
		//memset(vis,false,sizeof(vis));
		maxDepth=-1;
		fill(vis+1,vis+N+1,false);
		depthh[i] = DFS(i,1);
		globalMaxDepth=max(maxDepth,globalMaxDepth);
	}
	for(int i=1;i<=N;i++){
		if(depthh[i]==globalMaxDepth){
			printf("%d\n",depthh[i]);
		}
	}
}
