//PATA1115
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define maxn 1005
int N;
int a[maxn];
int height;
int numLast;
int numLastButNotLeast;
struct Node{
	Node* lchild, *rchild;
	int value;
	int layer;
};

Node* newNode(int x){
	Node* node = new Node;
	node->value=x;
	node->lchild=node->rchild=NULL;
	return node;
}

void insert(Node* &root, int x){
	if(root==NULL){
		root = newNode(x);
		return;
	}
	//if(x==root->value) return;
	//else 
	if(x <= root->value){
		insert(root->lchild,x);
	}else{
		insert(root->rchild,x);
	}
}

int getHeight(Node* root){
	if(root==NULL) return 0;
	else return max(getHeight(root->lchild),getHeight(root->rchild))+1;
}

void BFS(Node* root){
	queue<Node*> q;
	root->layer=1;
	q.push(root);
	while(!q.empty()){
		Node* now = q.front();
		q.pop();
		if(now->layer==height){
			numLast++;
		}else if(now->layer==height-1){
			numLastButNotLeast++;
		}
		if(now->lchild!=NULL){
			now->lchild->layer=now->layer+1;
			q.push(now->lchild);
		}
		if(now->rchild!=NULL){
			now->rchild->layer=now->layer+1;
			q.push(now->rchild);
		}
	}
}

int main(){
	cin>>N;
	Node* root = NULL;
	for(int i=0;i<N;i++){
		cin>>a[i];
		insert(root,a[i]);
	}
	//get the height of the tree
	height = getHeight(root);
	BFS(root);
	printf("%d + %d = %d",numLast,numLastButNotLeast,numLast+numLastButNotLeast);
}
