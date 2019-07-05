//PATA1074 19'
#include<cstdio>
#include<algorithm>
#include<iostream>
#define maxn 100005
using namespace std;
struct Node {
	int address,next,data;
	int order;
	Node() {
		order=maxn;
	}
} nodee[maxn];

int cmp(Node a,Node b) {
	return a.order<b.order;
}

int main() {
	int address,first,N,K;
	scanf("%d%d%d",&first,&N,&K);
	for(int i=0; i<N; i++) {
		scanf("%d",&address);
		scanf("%d%d",&nodee[address].data,&nodee[address].next);
		nodee[address].address=address;
	}
	int p=first,count=0;
	while(p!=-1) {
		nodee[p].order=count++;
		p=nodee[p].next;
	}
	sort(nodee,nodee+maxn,cmp);
	int left=0,right=count-1;
	int count2=0;
	while(left+K-1<=right){
		for(int i=left+K-1;i>=left;i--){
			nodee[i].order=count2++;
			if(i!=left){
				nodee[i].next=nodee[i-1].address;
			}else{
				if(left+K-1<right)
					nodee[i].next=nodee[left+K].address;
				else{
					nodee[i].next=-1;
				}
			}
		}
		left+=K;
	}
	sort(nodee,nodee+maxn,cmp);
	for(int i=0;i<count;i++){
		if(i!=count-1)
			printf("%05d %d %05d\n",nodee[i].address,nodee[i].data,nodee[i].next);
		else
			printf("%05d %d -1\n",nodee[i].address,nodee[i].data);
	}

}
