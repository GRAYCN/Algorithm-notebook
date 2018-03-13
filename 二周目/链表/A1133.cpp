//A1133
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
using namespace std;
#define maxn 100005
int first,N,K;
struct Node{
	int address;
	int data;
	int next;
	int inList;
	int negative;
	int lessAndEqualToK;
	int moreThanK;
	int rank;
	Node(){
		rank=9999999;
	}
}node[maxn];

int cmp(Node a, Node b){
	if(a.inList!=b.inList) return a.inList>b.inList;
	else if(a.negative!=b.negative) return a.negative>b.negative;
	else if(a.lessAndEqualToK!=b.lessAndEqualToK) return a.lessAndEqualToK>b.lessAndEqualToK;
	//else if(a.moreThanK!=
	else return a.rank<b.rank;
} 

int main(){
	cin>>first>>N>>K;
	int address,data,next; 
	for(int i=0;i<N;i++){
		cin>>address>>data>>next;
		 node[address].address=address;
		 node[address].data=data;
		 node[address].next=next;
	}
	int k=first;
	int cnt=0;
	//while(node[k].next!=-1){
	while(k!=-1){
		if (k==27777)
		{
			printf("");
		}
		node[k].inList=1;
		if(node[k].data<0){
			node[k].negative=1;
		}
		if(node[k].data>=0 && node[k].data<=K){
			node[k].lessAndEqualToK=1;
		}
		/*if (node[k].data>K)
		{
			node[k].moreThanK=1;
		}*/
		node[k].rank=cnt;
		k=node[k].next;
		cnt++;
	}
	sort(node,node+maxn,cmp);
	for(int i=0;i<cnt-1;i++){
		printf("%05d %d %05d\n",node[i].address,node[i].data,node[i+1].address);
	}
	int i=cnt-1;
	printf("%05d %d -1\n",node[i].address,node[i].data);
}
