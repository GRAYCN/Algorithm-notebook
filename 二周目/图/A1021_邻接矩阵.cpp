//A1021
//23' 有一个测试点超时
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
#include <vector>
#include <set>
#include <cstdio>
using namespace std;
#define maxn 10005

int N,M,K;
int e[maxn][maxn];
vector<int> v[maxn];
bool vis[maxn];
int maxDepth=-1;
set<int> result;

void DFS(int root,int index,int depth){
	if(root==4){
		printf("");
	}
	if(depth>maxDepth){
		maxDepth=depth;
		result.clear();
		result.insert(root);
	}else if(depth==maxDepth){
		result.insert(root);
	}
	vis[index]=true;
	for(int i=1;i<=N;i++){
		if(!vis[i] && e[i][index]==1){
			DFS(root,i,depth+1);
		}
	}
	//vis[index]=false;
}

int main(){
//	cin>>N;
	scanf("%d",&N);
	for(int i=0;i<N-1;i++){
		int a,b;
//		cin>>a>>b;
		scanf("%d%d",&a,&b);
		e[a][b]=e[b][a]=1;
	}
	for (int i=1;i<=N;i++)
	{
		fill(vis,vis+maxn,false);
		int cnt=0;
		DFS(i,i,0);
		cnt++;
		for(int j=1;j<=N;j++){
			if(!vis[j]){
				DFS(i,j,0);
				cnt++;
			}
		}
		if(cnt>1){
			printf("Error: %d components\n",cnt);
			return 0;
		}	
	}
	for(set<int>::iterator it=result.begin();it!=result.end();it++){
		printf("%d\n",*it);
	}
} 

