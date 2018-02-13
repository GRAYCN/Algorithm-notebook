//PATA1052
#include<cstdio>
#include<algorithm>
#define maxn 100005
using namespace std;
struct Node{
	int address,data,next;
	bool flag;
	Node(){
		flag=false;
	}
}node[maxn];

bool cmp(Node a, Node b){
//	if(a.flag==false ||b.flag==false){
	if(a.flag!=b.flag){
		return a.flag>b.flag;
	}else{
		return a.data<b.data;
	}
}

int main(){
	//初始化flag为false
//	for(int i=0;i<maxn;i++){
//		node[i].flag=false;
//	} 
	int n,begin,address;
	scanf("%d%d",&n,&begin);
	for(int i=0;i<n;i++){
		scanf("%d",&address);
		scanf("%d%d",&node[address].data,&node[address].next);
		node[address].address=address;
	}
	int count=0, p=begin;
	while(p!=-1){
		node[p].flag = true;
		count++;
		p=node[p].next;
	}
	if(count==0){		//特判，新链表中没有结点时输出0 -1 
		printf("0 -1");
	}else{
		sort(node,node+maxn,cmp);
		printf("%d %05d\n",count, node[0].address);
		for(int i=0;i<count;i++){
			if(i!=count-1){
				printf("%05d %d %05d\n",node[i].address,node[i].data,node[i+1].address);
			}else{
				printf("%05d %d -1\n",node[i].address,node[i].data);
			}
		}
	} 
}
