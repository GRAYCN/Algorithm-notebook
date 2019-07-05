//PATA1074
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
} node[maxn];

int cmp(Node a,Node b) {
	return a.order<b.order;
}

int main() {
	int address,N,K,begin;
	scanf("%d%d%d",&begin,&N,&K);
	for(int i=0; i<N; i++) {
		scanf("%d",&address);
		scanf("%d%d",&node[address].data,&node[address].next);
		node[address].address=address;
	}
	int p=begin,count=0;
	while(p!=-1) {
		node[p].order=count++;
		p=node[p].next;
	}
	sort(node,node+maxn,cmp);
	int count1=0;
	int n=count;
	for(int i=0; i<n/K; i++) {
		int j;
		for(j=i*K+K-1; j>i*K; j--) {
			count1++;
			printf("%05d %d %05d\n",node[j].address,node[j].data,node[j-1].address);
 		}
		//对第每一组的第一个做特殊处理
		count1++;
		printf("%05d %d ",node[j].address,node[j].data);
		if(i<n/K-1) {		
			printf("%05d\n",node[(i+2)*K-1].address);
		}else{
			if(n%K ==0){
				printf("-1\n");
			}else{
				printf("%05d\n",node[(i+1)*K].address);
				for(int i=n/K*K;i<n;i++){
					printf("%05d %d ",node[i].address,node[i].data);
					if(i<n-1){
						printf("%05d\n",node[i+1].address);
					}else{
						printf("-1\n");
					}
				}
			}
		}
	}
}
