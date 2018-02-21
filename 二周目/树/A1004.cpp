//A1004
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
#define maxn 105
struct Node{
	vector<int> child;
}node[maxn];
int N,M;

int maxDepth=-1;
int cnt[100];

void DFS(int root,int depth){
	if(node[root].child.size()==0){
		if(depth > maxDepth){
			maxDepth=depth;
		}
		cnt[depth]++;
	}

	for(int i=0;i<node[root].child.size();i++){
		DFS(node[root].child[i], depth+1);
	}
}
int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		int K,father;
		scanf("%d%d",&father,&K);
		for(int j=0;j<K;j++){
			int child;
			scanf("%d",&child);
			node[father].child.push_back(child);
		}
	}
	DFS(1,0);
	for(int i=0;i<=maxDepth;i++){
		printf("%d",cnt[i]);
		if(i!=maxDepth) printf(" ");
	}
}
