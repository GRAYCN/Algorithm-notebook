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
int result[maxn];
int maxLayer;
struct Node{
	int layer;
	vector<int> child;
}node[maxn];

void BFS(int root){
	queue<int> q;
	node[root].layer=0;
	q.push(root);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		maxLayer=max(maxLayer,node[now].layer);
		if(node[now].child.size()==0){
			result[node[now].layer]++;
		}
		for(int i=0;i<node[now].child.size();i++){
			int id=node[now].child[i];
			node[id].layer=node[now].layer+1;
			q.push(id);
		}
	}
}

int main(){
	int N,M,ID,K,child;
	cin>>N>>M;
	for(int i=0;i<M;i++){
		cin>>ID>>K;
		for(int i=0;i<K;i++){
			cin>>child;
			node[ID].child.push_back(child);
		}
	}
	BFS(1);
	for(int i=0;i<=maxLayer;i++){
		printf("%d",result[i]);
		if(i!=maxLayer)
			printf(" ");
	}
} 
