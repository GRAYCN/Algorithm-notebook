//A1026
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
#include <cstdio>
#include<vector>
#include<cmath>
using namespace std;
const int K = 111;
const int INF = 1000000000;
struct Player{
	int arriveTime,startTime,trainTime;
	bool isVIP;
}newPlayer;

struct Table{
	int endTime, numServe;
	bool isVIP;
}table[K];
vector<Player> player;
int convertTime(int h, int m, int s){
	return h*3600+m*60+s;
}

bool cmpArriveTime(Player a,Player b){
	return a.arriveTime<b.arriveTime;
}

bool cmpStartTime(Player a,Player b){
	return a.startTime<b.startTime;
}

int nextVIPPlayer(int VIPi){
	VIPi++;
	while(VIPi<player.size() && player[VIPi].isVIP == 0 ){
		VIPi++;
	}
	return VIPi;
}

void alloTable(int pID,int tID){
	if(player[pID].arriveTime <= table[tID].endTime){
		player[pID].startTime = table[tID].endTime;
	}else{
		player[pID].startTime = player[pID].arriveTime;
	}
	table[tID].endTime = player[pID].startTime+player[pID].trainTime;
	table[tID].numServe++;
}

int main(){
	int n,k,m,VIPtable;
	scanf("%d",&n);
	int stTime=convertTime(8,0,0);
	int edTime=convertTime(21,0,0);
	for(int i=0;i<n;i++){
		int h,m,s,trainTime,isVIP;
		cin>>h>>m>>s>>trainTime>>isVIP;
		newPlayer.arriveTime=convertTime(h,m,s);
		newPlayer.startTime=edTime;
		if(newPlayer.arriveTime>=edTime) continue;
		newPlayer.trainTime=trainTime<=120?trainTime*60:7200;
		newPlayer.isVIP=isVIP;
		player.push_back(newPlayer);
	}
	cin>>k>>m;
	for(int i=1;i<=k;i++){
		table[i].endTime=stTime;
		table[i].numServe=table[i].isVIP=0;
	}
	for(int i=0;i<m;i++){
		cin>>VIPtable;
		table[VIPtable].isVIP=1;
	}
	
	sort(player.begin(),player.end(),cmpArriveTime);
	int i=0,VIPi=-1;
	VIPi=nextVIPPlayer(VIPi);
	while(i<player.size()){
		int idx=-1, minEndTime=INF;
		for(int j=1;j<=k;j++){
			if(table[j].endTime<minEndTime){
				idx=j;
				minEndTime=table[j].endTime;
			}
		}
		if(table[idx].endTime>=edTime) break;
		if( player[i].isVIP && i <VIPi ){
			i++;
			continue;
		}
		
		if(table[idx].isVIP){
			if(player[i].isVIP){
				alloTable(i,idx);
				if(VIPi==i) VIPi=nextVIPPlayer(VIPi);
				i++;
			}else{
				if(VIPi<player.size() && 
				player[VIPi].arriveTime<=table[idx].endTime){
					alloTable(VIPi,idx);
					VIPi=nextVIPPlayer(VIPi);
				}else{
					alloTable(i,idx);
					i++;
				}
			}
		}else{
			if(!player[i].isVIP){
				alloTable(i,idx);
				i++;
			}else{
				int VIPidx=-1,minVIPEndTime=INF;
				for(int j=1;j<=k;j++){
					if(table[j].isVIP && table[j].endTime<minVIPEndTime){
						minVIPEndTime=table[j].endTime;
						VIPidx=j;
					}
				}
				//??
				if(VIPidx!=-1 && 
				player[i].arriveTime>=table[VIPidx].endTime){
					alloTable(i,VIPidx);
					if(VIPi==i) VIPi=nextVIPPlayer(VIPi);
					i++;
				}else{
					alloTable(i,idx);
					if(VIPi==i) VIPi=nextVIPPlayer(VIPi);
					i++;
				}
			}
		}
	}
	sort(player.begin(),player.end(),cmpStartTime);
	for(int i=0;i<player.size() && player[i].startTime<edTime;i++){
		int t1=player[i].arriveTime;
		int t2=player[i].startTime;
		printf("%02d:%02d:%02d ",t1/3600,t1%3600/60,t1%60);
		printf("%02d:%02d:%02d ",t2/3600,t2%3600/60,t2%60);
		printf("%.0f\n",round((t2-t1)/60.0));//??
	}
	for(int i=1;i<=k;i++){
		printf("%d",table[i].numServe);
		if(i<k) cout<<" ";
	}
}
