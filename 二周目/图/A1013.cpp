//A1013
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
#define maxn 1005

int N,M,K;
int e[maxn][maxn];
bool vis[maxn];

void DFS(int index){
	vis[index]=true;
	for(int i=1;i<=N;i++){
		if(!vis[i] && e[i][index]==1){
			DFS(i);
		}
	}
}

int main(){
	cin>>N>>M>>K;
	for(int i=0;i<M;i++){
		int a,b;
		cin>>a>>b;
		e[a][b]=e[b][a]=1;
	}
	for(int i=0;i<K;i++){
		fill(vis,vis+maxn,false);
		int query;
		cin>>query;
		vis[query]=true;
		int cnt=0;
		for(int i=1;i<=N;i++){
			if(!vis[i]){
				DFS(i);
				cnt++;
			}
		}
		cout<<cnt-1<<endl;
	}
} 

