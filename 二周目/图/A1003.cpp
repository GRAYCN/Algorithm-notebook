//
//  main.cpp
//  A1003
//
//  Created by mac on 18/2/16.
//  Copyright (c) 2018年 mac. All rights reserved.

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 99999999
#define maxn 510
int e[maxn][maxn];
bool vis[maxn];
int dis[maxn];
int numPeople[maxn];
int maxSum=-1;
vector<int> pre[maxn], path, tempPath;
int N,M,C1,C2;

void Dijkstra(int s){
	fill(dis, dis+maxn, INF);
	dis[s]=0;
	for (int i=0; i<maxn; i++) {
		int u=-1,min=INF;
		for (int j=0; j<maxn; j++) {
			if(!vis[j] && dis[j]<min){
				u=j;
				min=dis[j];
			}
		}
		if(u==-1) break;
		vis[u]=true;
		for (int v=0; v<maxn; v++) {
			if (!vis[v] && e[u][v]!=INF) {
				if (dis[v]>dis[u]+e[u][v]) {
					dis[v] = dis[u]+e[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(dis[v]==dis[u]+e[u][v]){
					pre[v].push_back(u);
				}
			}
		}
	}
}
int cnt=0;
void DFS(int index){
	if(index==C1){
		cnt++;
		tempPath.push_back(index);
		int sum=0;
		for (int i = tempPath.size()-1; i>=0; i--) {
			int id = tempPath[i];
			sum+=numPeople[id];
		}
		if(sum>maxSum){
			maxSum=sum;
			path=tempPath;
		}

		tempPath.pop_back();
		return;
	}
	tempPath.push_back(index);
	for (int i=0; i<pre[index].size(); i++) {
		int id=pre[index][i];
		DFS(id);
	}
	tempPath.pop_back();
}

int main() {

	cin>>N>>M>>C1>>C2;
	fill(e[0], e[0]+maxn*maxn, INF);
	for (int i=0; i<N; i++) {
		cin>>numPeople[i];
	}
	for (int i=0; i<M; i++) {
		int a,b,length;
		cin>>a>>b>>length;
		e[a][b]=e[b][a]=length;
	}
	Dijkstra(C1);
	DFS(C2);
	cout<< cnt <<" "<< maxSum;
	return 0;
}
