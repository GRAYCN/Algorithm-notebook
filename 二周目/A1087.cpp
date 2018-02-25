#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
using namespace std;
#define INF 99999999
#define maxn 210
int e[maxn][maxn];
bool vis[maxn];
int dis[maxn];
int happiness[maxn];
vector<int> pre[maxn], path, tempPath;
int N,K;
string start,endd="ROM";
map<string,int> strToInt;
map<int,string> intToStr;
int maxHapp=-1,maxAvgHapp=-1;
void Dijkstra(int s){
	fill(dis, dis+maxn, INF);
	fill(vis, vis+maxn, false);
	dis[s]=0;
	for (int i=1; i<=N; i++) {
		int u=-1,min=INF;
		for (int j=1; j<=N; j++) {
			if(!vis[j] && dis[j]<min){
				u=j;
				min=dis[j];
			}
		}
		if(u==-1) break;
		vis[u]=true;
		for (int v=1; v<=N; v++) {
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
/*
¨º?3??¨²¨¨Y¡êo
1.¡Á??¨¬?¡¤¦Ì?¨¬?¨ºy
2.¡Á??¨¬?¡¤3¡è?¨¨
3.?¨¬¨¤??¨¨
4.???¨´?¨¬¨¤??¨¨¡ê¡§?¨°??¨¨??? round down¡ê?
5.??DD
6.¨º?3??¡¤?? City1->City2->...->ROM
*/ 
int cnt=0;
void DFS(int index){
	if(index==1){
		cnt++;
		tempPath.push_back(index);
		int tempHappiness=0,tempAvgHappiness=0;
		for (int i = tempPath.size()-1; i>=0; i--) {
			int id = tempPath[i];
			tempHappiness+=happiness[id];
		}
		tempAvgHappiness=tempHappiness/(tempPath.size()-1);
		if(tempHappiness>maxHapp){
			maxHapp=tempHappiness;
			maxAvgHapp=tempAvgHappiness;
			path=tempPath;
		}else if(tempHappiness==maxHapp && tempAvgHappiness>maxAvgHapp){
			maxAvgHapp=tempAvgHappiness;
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
	cin>>N>>K>>start;
	strToInt[start]=1;
	intToStr[1]=start;
	for(int i=2;i<=N;i++){
		string name;
		int happ;
		cin>>name>>happ;
		strToInt[name]=i;
		intToStr[i]=name;
		happiness[i]=happ;
	} 
	fill(e[0], e[0]+maxn*maxn, INF);
	for (int i=0; i<K; i++) {
		string a,b;
		int distance;
		cin>>a>>b>>distance;	
		e[strToInt[a]][strToInt[b]]=e[strToInt[b]][strToInt[a]]=distance;
	}
	Dijkstra(1);
	DFS(strToInt[endd]);
	printf("%d %d %d %d\n",cnt,dis[strToInt[endd]],maxHapp,maxAvgHapp);
	for (int i = path.size()-1; i>=0; i--) {
		int id = path[i];
		cout<<intToStr[id];
		if(i!=0){
			cout<<"->";
		}
	}
}
