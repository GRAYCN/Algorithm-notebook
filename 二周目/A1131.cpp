//25'
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
#include <vector> 
#define maxn 10000
#define INF 100000000
using namespace std;
int N,M;
int line[maxn][maxn];
int start,endd;
vector<int> tempPath, path;
int minStop=INF, minTransfer=INF; 
vector<int> v[10000];
bool vis[maxn];

int countTransfer(){
	int cnt=0;
	int nowLine=line[path[0]][path[1]];
	for(int i=0;i<tempPath.size()-1;i++){
		int id1=tempPath[i],id2=tempPath[i+1];
		if(line[id1][id2]!=nowLine){
			cnt++;
			nowLine=line[id1][id2];
		}
	}
	return cnt;
}

void DFS(int index){
	vis[index]=true;
	if(index==endd){
		tempPath.push_back(index);
		if(tempPath.size()<minStop){
			minStop=tempPath.size();
			path=tempPath;
			int cnt=countTransfer();
			minTransfer=cnt;
			//minTransfer=countTransfer();
			
		} else if(tempPath.size() == minStop){
			int cnt=countTransfer();
			if(cnt<minTransfer){
				minTransfer=cnt;
				path=tempPath;
			}
		}
		tempPath.pop_back();
		return;
	}

	tempPath.push_back(index);
	for(int i=0;i<v[index].size();i++){
		if(vis[v[index][i]]==false){
			//vis[v[index][i]]=true;
			DFS(v[index][i]);
			vis[v[index][i]]=false;
		}	
	}
	tempPath.pop_back();
}

void print(){
	printf("%d\n",path.size()-1);
	int nowLine=line[path[0]][path[1]],lastStation=path[0];
	for(int i=0;i<path.size()-1;i++){
		int id1=path[i],id2=path[i+1];
		if(line[id1][id2]!=nowLine ){
			printf("Take Line#%d from %04d to %04d.\n",nowLine,lastStation,id1);
			nowLine=line[id1][id2];
			lastStation=id1;
		}
		if(id2==endd){
			printf("Take Line#%d from %04d to %04d.\n",nowLine,lastStation,id2);
		}
	}	
}


int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		int now,next;
		scanf("%d",&M);
		scanf("%d",&now);
		int cnt=1;
		while(cnt!=M){
			scanf("%d",&next);
			v[now].push_back(next);
			v[next].push_back(now);
			line[now][next]=line[next][now]=i;
			now=next;
			cnt++;
		}
	}
	int K;
	scanf("%d",&K);
	for(int i=0;i<K;i++){
		scanf("%d%d",&start,&endd);
		minStop=INF, minTransfer=INF; 
		tempPath.clear();
		path.clear();
		fill(vis,vis+maxn,false);
		DFS(start);
		print();
	}	
}
