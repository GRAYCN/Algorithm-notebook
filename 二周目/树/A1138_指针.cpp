//A1138 	ָ�뷽ʽ 
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstdio> 
using namespace std;
#define maxn 50005
struct Node{
	Node* lchild, *rchild;
	int data;
};
int pre[maxn],in[maxn];
vector<int> post;

Node* build(int preL, int preR, int inL, int inR){
	if(preL>preR) return NULL;
	Node* root = new Node;
	root->data=pre[preL];
	int k=inL;
	for(;k<=inR;k++){
		if(in[k]== root->data)
			break;
	}
	int numLeft=k-inL;
	root->lchild=build(preL+1,preL+numLeft,inL,k-1);
	root->rchild=build(preL+numLeft+1,preR,k+1,inR);
	return root;
}
int cnt=0;
void postOrder(Node* root){
	if(!root) return;
	postOrder(root->lchild);
	postOrder(root->rchild);
	if(cnt==0){
		printf("%d",root->data);
		cnt++;
		exit(0);
	} 
	
//	post.push_back(root->data);
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
	Node* root = build(0,N-1,0,N-1);
	postOrder(root);
//	printf("%d",post[0]);
}
