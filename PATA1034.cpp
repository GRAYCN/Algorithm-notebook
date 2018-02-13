//PATA1034
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
#define maxn 2005
#define inf 10000000000
map<int,string> intToString;	//���->���� 
map<string,int> stringToInt;	//����->���
map<string,int> Gang;			//head->���� 
int e[maxn][maxn];		//��¼��Ȩ�����������˫����ͨ��ʱ�� 
int w[maxn];			//��¼��Ȩ
bool vis[maxn]; 

int N,K;
int numPerson;			//ʵ�ʽ��ĸ��� 
int change(string str){
	if(stringToInt.find(str)!=stringToInt.end()){
		return stringToInt[str];
	}else{
		stringToInt[str]=numPerson;
		intToString[numPerson]=str;
		return numPerson++;
	}

}
int numGang;		//��������
int head;			//����ͷ�� 
int maxTime=-1;		//ͨ����õ�ʱ��
int totalTime=0;	//��ͨ��ʱ�� 
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
			numGang=0;		//���³�ʼ��
			head=i;
			totalTime=0;
			maxTime=-1;
			DFS(i);
			if(numGang>2 && totalTime>K){		//����һ������ 
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
