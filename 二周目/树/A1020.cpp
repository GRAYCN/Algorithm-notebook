//A1020
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Node{
	Node* lchild, *rchild;
	int data;
};
int post[35],in[35];

Node* build(int postL, int postR, int inL, int inR){
	if(postL>postR) return NULL;
	Node* root = new Node;
	root->data=post[postR];
	int k=inL;
	for(;k<=inR;k++){
		if(in[k]== root->data)
			break;
	}
	int numLeft=k-inL;
	root->lchild=build(postL,postL+numLeft-1,inL,k-1);
	root->rchild=build(postL+numLeft,postR-1,k+1,inR);
	return root;
}

void BFS(Node* root){
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node* now = q.front();
		q.pop();
		if(now->lchild) q.push(now->lchild);
		if(now->rchild) q.push(now->rchild);
		printf("%d",now->data);
		if(!q.empty()){
			printf(" ");
		}
	}
}

int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>post[i];
	}
	for(int i=0;i<N;i++){
		cin>>in[i];
	}
	Node* root = build(0,N-1,0,N-1);
	BFS(root);
}
