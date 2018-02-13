//PATA1097
#include<cstdio> 
#include<vector>
#include<algorithm>
#include<math.h>
#define maxn 100005
using namespace std;
//Node中key的hash
bool hashTable[maxn]; 
struct Node{
	int address,key,next;
	int order;
	Node(){
		order=maxn;
	}
}node[maxn];
vector<Node> u,v;		//u是去重后的内容，v是去重部分组成的内容 

int cmp(Node a,Node b){
	return a.order<b.order;
}

int main(){
	int begin,N;
	scanf("%d%d",&begin,&N);
	for(int i=0;i<N;i++){
		int address;
		scanf("%d",&address);
		scanf("%d%d",&node[address].key,&node[address].next);
		node[address].address=address;
	}
	int p=begin; 
	int count=0;
	while(p!=-1){
		node[p].order=count++;
		p=node[p].next;
	}
	sort(node,node+maxn,cmp);
	for(int i=0;i<count;i++){
		int test=node[i].key;
		if(hashTable[abs(node[i].key)]==false){
			hashTable[abs(node[i].key)]=true;
			u.push_back(node[i]);	
		}else{
			v.push_back(node[i]);
		}
	}
	for(int i=0;i<u.size();i++){
		if(i!=u.size()-1){
			printf("%05d %d %05d\n",u[i].address,u[i].key,u[i+1].address);
		}
		else{
			printf("%05d %d -1\n",u[i].address,u[i].key);
		}
	}

	for(int i=0;i<v.size();i++){
		if(i!=v.size()-1){
			printf("%05d %d %05d\n",v[i].address,v[i].key,v[i+1].address);
		}
		else{
			printf("%05d %d -1\n",v[i].address,v[i].key);
		}
	}
}

