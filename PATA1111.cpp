//PATA1111
//devcpp
#include<iostream>
#include<vector>
using namespace std;
#define maxn 510
#define INF 1000000000
int length[maxn][maxn];
bool vis[maxn];
int dis_length[maxn],dis_time[maxn];
int timee[maxn][maxn];
int minTime=INF,minInter=INF;
int N,M;
int s,d;
vector<int> tempPath_length,path_length,tempPath_time,path_time;
vector<int> pre_length[maxn], pre_time[maxn];
void Dijkstra_length(int s){
	fill(vis,vis+maxn,false);
	fill(dis_length,dis_length+maxn,INF);
	dis_length[s]=0;
	for(int i=0;i<N;i++){
		int u=-1,min=INF;
		for(int j=0;j<N;j++){
			if(!vis[j] && dis_length[j]<min){
				u=j;
				min=dis_length[u];
			}
		}
		if(u==-1) break;
		vis[u]=true;
		for(int v=0;v<N;v++){
			if(!vis[v] && length[u][v]!=INF){
				if(dis_length[v]>dis_length[u]+length[u][v]){
					dis_length[v]=dis_length[u]+length[u][v];
					pre_length[v].clear();
					pre_length[v].push_back(u);
				}else if(dis_length[v] == dis_length[u]+length[u][v]){
					pre_length[v].push_back(u);
				}
			}
		}
	}
}

void Dijkstra_time(int s){
	fill(vis,vis+maxn,false);	
	fill(dis_time,dis_time+maxn,INF);
	dis_time[s]=0;
	for(int i=0;i<N;i++){
		int u=-1,min=INF;
		for(int j=0;j<N;j++){
			if(!vis[j] && dis_time[j]<min){
				u=j;
				min=dis_time[u];
			}
		}
		if(u==-1) break;
		vis[u]=true;
		for(int v=0;v<N;v++){
			if(!vis[v] && timee[u][v]!=INF){
				if(dis_time[v]>dis_time[u]+timee[u][v]){
					dis_time[v]=dis_time[u]+timee[u][v];
					pre_time[v].clear();
					pre_time[v].push_back(u);
				}else if(dis_time[v] == dis_time[u]+timee[u][v]){
					pre_time[v].push_back(u);
				}
			}
		}
	}
}

void DFS_length(int index){
	if(index==s){
		tempPath_length.push_back(index);
		int thisTime=0;
		for(int i=tempPath_length.size()-1;i>0;i--){
			int id1=tempPath_length[i],id2=tempPath_length[i-1];
			thisTime+=timee[id1][id2];
		}
		if(thisTime<minTime){
			minTime=thisTime;
			path_length=tempPath_length;
		}
		tempPath_length.pop_back();
	}
	tempPath_length.push_back(index);
	for(int i=0;i<pre_length[index].size();i++){
		DFS_length(pre_length[index][i]);
	}
	tempPath_length.pop_back();
}

void DFS_time(int index){
	if(index==s){
		tempPath_time.push_back(index);
		int thisInter=tempPath_time.size();
		if(thisInter<minInter){
			minInter=thisInter;
			path_time=tempPath_time;
		}
		tempPath_time.pop_back();
	}
	tempPath_time.push_back(index);
	for(int i=0;i<pre_time[index].size();i++){
		DFS_time(pre_time[index][i]);
	}
	tempPath_time.pop_back();
}

int main(){
	cin>>N>>M;
	fill(length[0],length[0]+maxn*maxn,INF);
	fill(timee[0],timee[0]+maxn*maxn,INF);
	for(int i=0;i<M;i++){
		int v1,v2,one_way,l,t;
		cin>>v1>>v2>>one_way>>l>>t;
		length[v1][v2]=l;
		timee[v1][v2]=t;
		if(one_way==0){
			length[v2][v1]=l;
			timee[v2][v1]=t;
		}
	}
	cin>>s>>d;
	Dijkstra_length(s);
	DFS_length(d);
	Dijkstra_time(s);
	DFS_time(d);

	int Distance=0,Time=0;
	for(int i=path_length.size()-1;i>0;i--){
		int id1=path_length[i],id2=path_length[i-1];
		Distance+=length[id1][id2];
	}
	for(int i=path_time.size()-1;i>0;i--){
		int id1=path_time[i],id2=path_time[i-1];
		Time+=timee[id1][id2];
	}

	//output:
	if(path_length!=path_time){
		printf("Distance = %d: ",Distance);
		for(int i=path_length.size()-1;i>=0;i--){
			printf("%d",path_length[i]);
			if(i>0) printf(" -> ");
		}
		printf("\n");
		printf("Time = %d: ",Time);
		for(int i=path_time.size()-1;i>=0;i--){
			printf("%d",path_time[i]);
			if(i>0) printf(" -> ");
		}
		printf("\n");
	}else{
		printf("Distance = %d; Time = %d: ",Distance,Time);
		for(int i=path_length.size()-1;i>=0;i--){
			printf("%d",path_length[i]);
			if(i>0) printf(" -> ");
		}
	}
}
