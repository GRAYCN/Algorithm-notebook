//PATA1020
#include<iostream>
#include<cstdio>
#include<queue>
#define maxn 50
using namespace std;
struct node {
	node* lchild;
	node* rchild;
	int data;
};

int pre[maxn],in[maxn],post[maxn];
int n;

node* build(int postL, int postR, int inL, int inR){
	if(postL>postR) return NULL;
	node* root = new node;
	root->data=post[postR];
	int k;
	for(k=inL;k<=inR;k++){
		if(in[k]==post[postR]){
			break;
		}
	}
	int numLeft=k-inL;
	root->lchild=build(postL,postL+numLeft-1,inL,k-1);
	root->rchild=build(postL+numLeft,postR-1,k+1,inR);
	return root;

}

int num=0;		//已输出的结点数 
void BFS(node* root){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* now = q.front();
		q.pop();
		cout<<now->data;
		num++;
		if(num<n)
		cout<<" ";
		if(now->lchild!=NULL) q.push(now->lchild);
		if(now->rchild!=NULL) q.push(now->rchild);
	}
}

int main() {
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>post[i];
	}
	for(int i=0; i<n; i++) {
		cin>>in[i];
	}
	node* root=build(0,n-1,0,n-1);
	BFS(root);
}
