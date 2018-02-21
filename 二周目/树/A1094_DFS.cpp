//A1094
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
int cnt[105];
void DFS(int root,int depth){
	cnt[depth]++;
	for(int i=0;i<node[root].child.size();i++){
		DFS(node[root].child[i], depth+1);
	}
}
int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		int father,K;
		scanf("%d%d",&father,&K);
		for(int j=0;j<K;j++){
			int child;
			scanf("%d",&child);
			node[father].child.push_back(child);
		}
	}
	DFS(1,1);
	int index=0;
	for(int i=1;i<=100;i++){
		if(cnt[i]>cnt[index]){
			index=i;
		}
	}
	printf("%d %d",cnt[index],index);
}
