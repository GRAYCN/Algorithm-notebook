//PATA1034
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
#define maxn 2005
#define inf 10000000000
map<int,string> intToString;	//编号->姓名 
map<string,int> stringToInt;	//姓名->编号
map<string,int> Gang;			//head->人数 
int e[maxn][maxn];		//记录边权，在这里就是双方的通话时长 
int w[maxn];			//记录点权
bool vis[maxn]; 

int N,K;
int numPerson;			//实际结点的个数 
int change(string str){
	if(stringToInt.find(str)!=stringToInt.end()){
		return stringToInt[str];
	}else{
		stringToInt[str]=numPerson;
		intToString[numPerson]=str;
		return numPerson++;
	}

}
int numGang;		//帮派人数
int head;			//帮派头领 
int maxTime=-1;		//通话最久的时间
int totalTime=0;	//总通话时间 
void DFS(int index){
	vis[index]=true;
	numGang++;
	if(w[index]>maxTime){
		maxTime=w[index];
		head=index;
	} 

	for(int i=0;i<numPerson;i++){
		if(e[index][i]>0 ){
			totalTime+=e[index][i];
			e[index][i]=e[i][index]=0;
			if( vis[i]==false)
				DFS(i);
		}
	}
}

void DFSTrave(){
	for(int i=0;i<numPerson;i++){
		if(vis[i]==false){
			numGang=0;		//重新初始化
			head=i;
			totalTime=0;
			maxTime=-1;
			DFS(i);
			if(numGang>2 && totalTime>K){		//这是一个帮派 
				Gang[intToString[head]]=numGang;
			} 
		}
	}
}

int main(){
	cin>>N>>K;
	string a,b;
	int time;
	for(int i=0;i<N;i++){
		cin>>a>>b>>time;
		int id1=change(a);
		int id2=change(b);
		w[id1]+=time;
		w[id2]+=time;
		e[id1][id2]+=time;
		e[id2][id1]+=time;
	}
	DFSTrave();
	cout<<Gang.size()<<endl;
	for(auto it=Gang.begin();it!=Gang.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}
}
