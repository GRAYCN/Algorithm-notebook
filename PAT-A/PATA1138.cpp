//PATA1138
//给定先序和中序序列，输出后序序列
#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
struct node {
	node* lchild;
	node* rchild;
	int data;
};
int N;
vector<int> pre,in;

node* create(int preL,int preR,int inL, int inR) {
	if(preL>preR) return NULL;
	node* root = new node;
	root->data=pre[preL];
	int k;
	for(k=inL; k<=inR; k++) {
		if(in[k] == pre[preL]) break;
	}
	int numLeft = k-inL;
	root->lchild=create(preL+1,preL+numLeft,inL,k-1);
	root->rchild=create(preL+numLeft+1,preR,k+1,inR);
	return root;
}
int num=0;
void DFS(node* root) {
	if(num>=1) return;
	if(root ==NULL) return;
	if(root->lchild!=NULL) DFS(root->lchild);
	if(root->rchild!=NULL) DFS(root->rchild);
	if(num>=1) return;
	cout<<root->data;
	num++;
}

//void DFS(node* root) {
//	if(root ==NULL) return;
//	if(root->lchild!=NULL) DFS(root->lchild);
//	if(root->rchild!=NULL) DFS(root->rchild);
//	num++;
//	if(num==1)
//		cout<<root->data;
//}

int main() {
//	scanf("%d",&N);
cin>>N;
	int temp;
	for(int i=0; i<N; i++) {
//		scanf("%d",&temp);
		cin>>temp;
		pre.push_back(temp);
	}
	for(int i=0; i<N; i++) {
//		scanf("%d",&temp);
		cin>>temp;
		in.push_back(temp);
	}
	node* root = create(0,N-1,0,N-1);
	DFS(root);
}
