//A1086
#include<iostream>
#include<cstring>
#include <string>
#include<algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct Node{
	Node* lchild, *rchild;
	int data;
};
vector<int> pre, in,post;
stack<int> s;

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

void postOrder(Node* root){
	if(!root) return;
	postOrder(root->lchild);
	postOrder(root->rchild);
	post.push_back(root->data);
}

int main(){
	int N;
	string ops;
	cin>>N;
	for(int i=0;i<2*N;i++){
		cin>>ops;
		if(ops=="Push"){
			int num;
			cin>>num;
			s.push(num);
			pre.push_back(num);
		}else{
			int num=s.top();
			s.pop();
			in.push_back(num);
		}

	}
	Node* root = build(0,N-1,0,N-1);
	postOrder(root);
	for(int i=0;i<post.size();i++){
		printf("%d",post[i]);
		if(i!=post.size()-1) printf(" ");
	}
}
