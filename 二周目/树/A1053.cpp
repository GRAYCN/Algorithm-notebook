//A1053
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
	int weight;
}node[maxn];
int N,M,S;

int maxDepth=-1;
int cnt[100];
vector<int> path,tempPath;

void print(){
	for(int i=0;i<path.size();i++){
		printf("%d",node[path[i]].weight);
		if(i!=path.size()-1) printf(" ");
	}
	printf("\n");
}

void DFS(int root,int depth,int sum){
	if (root==9)
	{
		printf("");
	}
	if(node[root].child.size()==0 && sum==S){
		path.push_back(root);
		print();
		path.pop_back();
		return;
	}
	if(node[root].child.size()==0 || sum>=S){
		return;
	}

	path.push_back(root);
	for(int i=0;i<node[root].child.size();i++){
		int id=node[root].child[i];
		DFS(id, depth+1,sum+node[id].weight);
	}
	path.pop_back();
}

int cmp(int a,int b){
	return node[a].weight>node[b].weight;
}

int main(){
	scanf("%d%d%d",&N,&M,&S);
	for(int i=0;i<N;i++){
		scanf("%d",&node[i].weight);
	}
	for(int i=0;i<M;i++){
		int ID,K;
		scanf("%d%d",&ID,&K);
		for(int i=0;i<K;i++){
			int child;
			scanf("%d",&child);
			node[ID].child.push_back(child);
		}
		sort(node[ID].child.begin(),node[ID].child.end(),cmp);
	}
	DFS(0,0,node[0].weight);
}
