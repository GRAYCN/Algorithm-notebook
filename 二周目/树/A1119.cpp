//A1119
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;
#define maxn 35
struct Node{
	Node* lchild, *rchild;
	int data; 
};
int pre[maxn],post[maxn];
vector<int> in;
bool flag=true;
Node* create(int preL, int preR, int postL, int postR){
	if(preL>preR) return NULL;
	Node* node = new Node;
	node->data=post[postR];
	node->lchild=node->rchild=NULL;
	int k;
	for(k=preL+1;k<=preR;k++){
		if(pre[k] == post[postR-1]) break;
	}
	int numLeft=k-1-preL;
	if(k-preL>1){
		node->lchild=create(preL+1,k-1,postL,postL+numLeft-1);
		node->rchild=create(k,preR,postL+numLeft,postR-1);
	}else{
		flag=false;
		node->rchild=create(k,preR,postL+numLeft,postR-1);
	}
	return node;
}

//int build(int preL, int preR, int inL, int inR){
//	if(preL>preR) return -1;
//	int root = preL;
//	int k=inL;
//	for(;k<=inR;k++){
//		if(in[k]== root)
//			break;
//	}
//	int numLeft=k-inL;
//	node[root].lchild=build(preL+1,preL+numLeft,inL,k-1);
//	node[root].rchild=build(preL+numLeft+1,preR,k+1,inR);
//	return root;
//}

void BFS(Node* root){
	 queue<Node*> q;
	 q.push(root);
	 while(!q.empty()){
	 	Node* now = q.front();
	 	q.pop();
	 	in.push_back(now->data);
	 	if(now->lchild) q.push(now->lchild);
		if(now->rchild) q.push(now->rchild); 
	}
}

int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>pre[i];
	}
	for(int i=0;i<N;i++){
		cin>>in[i];
	}
	Node* root = create(0,N-1,0,N-1);
	BFS(root);
	if(flag){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	for(int i=0;i<in.size();i++){
		printf("%d",in[i]);
		if(i!=in.size()-1){
			printf(" ");
		}
	}
}
