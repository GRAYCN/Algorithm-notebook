#include<iostream>
#include<cstdio>
using namespace std;
#include<algorithm>
#define maxn 100005
struct Node{
	int address;
	int data;
	int next;
	int flag;
	int moreThanK;
	int negative;
	int rank;
}node[maxn];

bool cmp(Node a,Node b){
	if(a.flag!=b.flag) return a.flag>b.flag;
	else if(a.negative!=b.negative) return a.negative>b.negative;
	else if(a.moreThanK!=b.moreThanK) return a.moreThanK<b.moreThanK;
	else return a.rank<b.rank;
}

int main(){
	int first,N,K;
	cin>>first>>N>>K;
	for(int i=0;i<N;i++){
		node[i].flag=0;
		node[i].moreThanK=0;
		node[i].negative=0;
	}
	for(int i=0;i<N;i++){
		int address,data,next;
		cin>>address>>data>>next;
		node[address].address=address;
		node[address].data=data;
		node[address].next=next;
	}
	int k;
	int cnt=0;
	for(k=first;k!=-1;k=node[k].next){
		node[k].flag=1;
		node[k].rank=cnt++;
		if(node[k].data>K){
			node[k].moreThanK=1;
		}
		if (node[k].data<0)
		{
			node[k].negative=1;
		}
	}

	sort(node,node+maxn,cmp);
	//if (N=)
	//{
	//	printf("%05d %d -1\n",node[0].address,node[0].data);
	//	return 0;
	//}
	for(int i=0;i<cnt;i++){
		if(i!=cnt-1){
			printf("%05d %d %05d\n",node[i].address,node[i].data,node[i+1].address);
		}else{
			printf("%05d %d -1\n",node[i].address,node[i].data);		
		}
	}
} 

