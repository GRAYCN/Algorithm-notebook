//有一个测试点超时，可以参考算法笔记上的解析和柳婼给出的解题思路 
//PATA1021
#include<vector>
#define maxn 10005 
#include<cstdio>
#include<algorithm>
#include <set>
using namespace std;
vector<int> Adj[maxn];	//adj table
set<int> ans;
bool vis[maxn];
int n;
int maxDepth=-1;
int lvl;
int cnt[maxn];

int dfs(int root, int l){
	vis[root]=true;
	lvl=max(lvl,l);
	for(int i=0;i<Adj[root].size();i++){
		if(!vis[Adj[root][i]]){
			dfs(Adj[root][i],l+1);
		}
	}
	return lvl;
}

void DFS(int index,int depth,int root) {
	vis[index]=true;
	if(depth>maxDepth) {
		maxDepth=depth;
		ans.clear();
		//ans.push_back(root);
		ans.insert(root);
	} else if(depth==maxDepth) {
		//ans.push_back(root);
		ans.insert(root);
	}

	for(int i=0; i<Adj[index].size(); i++) {
		int j=Adj[index][i];
		if(!vis[j]) {
			DFS(j,depth+1,root);
		}
	}
}

int main() {
	scanf("%d",&n);
	int a,b;
	for(int i=0; i<n-1; i++) {
		scanf("%d%d",&a,&b);
//		cin>>a>>b;
		Adj[a].push_back(b);
		Adj[b].push_back(a);
	}
	//采用深度优先搜素遍历，找最大深度
	int maxcnt=0;
	int comp=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			comp++;
			dfs(i,0);
		}
	}
	if(comp!=1){
		printf("Error: %d components\n",cnt);
		return 0;
	}
	for(int i=1;i<=n;i++){
		lvl=0;
		for(int j=1;j<=n;++j){
			vis[j]=false;
		}
		cnt[i]=dfs(i,0);
		maxcnt=max(maxcnt,lvl);
	}
	for(int i=1;i<=n;i++){
		if(cnt[i]=maxcnt){
			printf("%d\n",i);
		}
	}
	
	
//	for(int i=1; i<=N; i++) {
//		//memset(vis,false,sizeof(vis));
//		fill(vis+1,vis+N+1,false);
//		cnt=0;
//		DFS(i,1,i);
//		cnt++;
//		for(int j=1; j<=N; j++) {
//			if(!vis[j]) {
//				DFS(j,1,i);
//				cnt++;
//			}
//		}
//		if(cnt>1) {
//			printf("Error: %d components\n",cnt);
//			return 0;
//		}
//	}
//	for (auto it=ans.begin();it!=ans.end();it++)
//	{
////		cout<<*it<<endl;
//		printf("%d\n",*it);
//	}
}
