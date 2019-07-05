//PATA1066
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node {
	node* lchild,*rchild;
	int data;
	int height;
};
vector<int> v;
int N;



node* newNode(int data) {
	node* Node = new node;
	Node->data=data;
	Node->lchild=NULL;
	Node->rchild=NULL;
	Node->height=1; 
}

int getHeight(node* root) {
	return root->height;
}

void updateHeight(node* root) {
	int height = max(getHeight(root->lchild),getHeight(root->rchild))+1;
	root->height=height;
}



int getFactor(node* root) {
	return getHeight(root->lchild)-getHeight(root->rchild);
}

void L(node* &root){
	node* temp = root->rchild;
	root->rchild=temp->lchild;
	temp->lchild=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
}

void R(node* &root){
	node* temp = root->rchild;
	root->lchild=temp->rchild;
	temp->rchild=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
}

void insert(node* &root, int data) {
	if(root==NULL) {
		root=newNode(data);
		return;
	}
	if(root->data<data) {
		insert(root->lchild,data);
		updateHeight(root);
		if(getFactor(root->lchild)==1) {
			R(root);
		} else if(getFactor(root->lchild)==-1) {
			L(root->lchild);
			R(root);
		}
	} else if(root->data>data) {
		insert(root->rchild,data);
		updateHeight(root);
		if(getFactor(root->rchild)==-1) {
			L(root);
		} else if(getFactor(root->rchild)==1) {
			R(root->rchild);
			L(root);
		}
	}
}

node* create() {
	node* root = NULL;
	for(int i=0; i<v.size(); i++) {
		insert(root,v[i]);
	}
	return root;
}

int main() {
	cin>>N;
	for(int i=0; i<N; i++) {
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	node* root=create();
	cout<<root->data;
}
