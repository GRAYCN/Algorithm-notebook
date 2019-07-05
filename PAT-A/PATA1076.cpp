//PATA1076
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define maxn 1005
int e[maxn][maxn];
bool vis[maxn];
struct Node{
	int v;
	int layer;
};
vector<Node> Adj[maxn];
int cnt;
int N,L;
void BFS(int index){
	vis[index]=true;
	queue<Node> q;
	Node first;
	first.v=index;
	first.layer=0;
	q.push(first);
	while(!q.empty()){
		Node now = q.front();
		q.pop();
		if(now.layer>=1 && now.layer<=L)
			cnt++;
		int n=now.v;
		for(int i=0;i<Adj[n].size();i++){
			Node temp=Adj[n][i];
			if(!vis[temp.v]){
				temp.layer=now.layer+1;
				q.push(temp);
				vis[temp.v]=true;
			}
		}
	}
}


int main(){
	cin>>N>>L;
	for(int i=1;i<=N;i++){
		int num;
		cin>>num;
		for(int j=0;j<num;j++){
			int k;
			cin>>k;
			Node node;
			node.v=i;
			Adj[k].push_back(node);		//有向图，表示i关注k，k发布的内容能够被i转发出去 
		}
	}
	int K;
	cin>>K;
	for(int i=0;i<K;i++){
		int query;
		cin>>query;
		BFS(query);
		cout<<cnt<<endl;
		//初始化
		 cnt=0;
		 for(int i=0;i<maxn;i++){
		 	vis[i]=false;
		 }
	}
	
}

