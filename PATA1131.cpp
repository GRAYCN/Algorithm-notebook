//still wrong
//PATA1131
#include<iostream>
#include<vector>
using namespace std;
struct Node{
	int id;
	vector<int> stationId;
	vector<int> adj;
}node[10000]; 
bool visit[10000];
int S,D;

vector<int> path,tempPath;
int minTransfer=99999999,minSize=99999999;

int check(int id1,int id2){
	for(int i=0;i<node[id1].stationId.size();i++){
		for(int j=0;j<node[id2].stationId.size();j++){
			if(node[id1].stationId[i]==node[id2].stationId[j]){
				return node[id1].stationId[i];
			}
		}
	}
	return 0;
}

void DFS(int index){
	if (index==6666)
	{
		printf("");
	}
	minTransfer=99999999;
	if(index==D){
		tempPath.push_back(index);
		visit[index]=true;
		if(tempPath.size()<minSize){
			path=tempPath;
		}else if(tempPath.size() == minSize){
			int transfer=0;
			for(int i=0;i<tempPath.size()-1;i++){
				int id1=tempPath[i],id2=tempPath[i+1];
				if(!check(id1,id2)){
					transfer++;
				}
			}
			if(transfer<minTransfer){
				minTransfer=transfer;
			}
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(index);
	visit[index]=true;
	for(int i=0;i<node[index].adj.size();i++){
		int id=node[index].adj[i];
		if (!visit[id])
		{
			DFS(id);
		}
	}
	tempPath.pop_back();
}

int main(){
	int N,M,id1,id2,K;
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>M;
		cin>>id1;
		node[id1].id=id1;
		node[id1].stationId.push_back(i);
		for(int j =1;j<M;j++){
			cin>>id2;
			node[id2].id=id2;
			node[id2].stationId.push_back(i);
			node[id1].adj.push_back(id2);
			node[id2].adj.push_back(id1);
			id1=id2;
		}
	}
	cin>>K;
	for(int i=0;i<K;i++){
		cin>>S>>D;
		fill(visit,visit+10000,false);
		DFS(S);
		printf("%d\n",path.size()-1);
		int location1,location2;
		for(int i=0;i<path.size()-1;i++){
			if(i==0){
				location1=path[i];
			}
			int id1=path[i],id2=path[i+1];
			if(!check(id1,id2)){
				location2=path[i];
				printf("Take Line#%d from %04d to %04d.",
					check(path[i-1],path[i]),node[location1].id,node[location2].id);
				location1=location2;
			}else if (id2==D)
			{
				printf("Take Line#%d from %04d to %04d.\n",
					check(path[i-1],path[i]),node[location1].id,node[id2].id);
			}
		}
	}
}
