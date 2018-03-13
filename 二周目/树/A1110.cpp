//A1110
//一个测试点有误，还有内存超限的错误 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std; 
#define maxn 25

struct Node{
	int lchild,rchild;
}node[maxn];

int N;
bool isRoot[maxn];

bool flag=true;
bool firstEmpty=true;
int lastIndex=-1;
void BFS(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int now = q.front();
		if(now!=-1){
			lastIndex=now;	
		}
		
		q.pop();
		if(now==-1 && firstEmpty){
			firstEmpty=false;
		} 
		if(now!=-1 && !firstEmpty){ 
			flag=false;
			return;
		} 
		if(now!=-1){
			q.push(node[now].lchild);
			q.push(node[now].rchild);
		}
//		if(q.empty()){
//			lastIndex=now;	
//		}
	}
}

//void BFS(int root){
//	queue<int> q;
//	q.push(root);
//	while(!q.empty()){
//		int p= q.front();
//		if(p != -1){
//			q.push(node[p].lchild);
//			q.push(node[p].rchild);
//			lastIndex=p;
//			if(flag){
//				printf("NO %d\n",root);
//				exit(0);
//			}
//		}else{
//			flag= true;
//		}
//		q.pop();
//	}
//	printf("YES %d\n",lastIndex);
//	exit(0);
//} 

int main(){
	cin>>N;
	fill(isRoot,isRoot+maxn,true);	
	for(int i=0;i<N;i++){
		char l[3],r[3];
		scanf("%s %s", l, r);
		if(l[0]=='-'){
			node[i].lchild=-1;	
		}else{
			int child=l[0]-'0';
			if(strlen(l)==2){
				child=10*child+l[1]-'0';
			}
			node[i].lchild=child;
			
			isRoot[child]=false;
		}
		
		if(r[0]=='-'){
			node[i].rchild=-1;	
		}else{
			int child=r[0]-'0';
			if(strlen(r)==2){
				child=10*child+r[1]-'0';
			}
			node[i].rchild=child;
			
			isRoot[child]=false;
		}
	}
	int root=0;
	for(int i=0;i<N;i++){
		if(isRoot[i]) root=i;
	}
	BFS(root);
	if(flag){
		printf("YES %d",lastIndex);
	}else{
		printf("NO %d",root);
	}
} 
