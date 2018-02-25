#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
#include <queue>
using namespace std;
struct Node{
	int v,height;
	Node *lchild, *rchild;
};

int a[25];

Node* newNode(int x){
	Node* node = new Node;
	node->v=x;
	node->height=1;
	node->rchild=node->lchild=NULL;
	return node;
}

int getHeight(Node *root){
	if(root==NULL) return 0;
	return root->height;
}

int getBF(Node* root){
	return getHeight(root->lchild)-getHeight(root->rchild);
}

void updateHeight(Node* root){
	root->height=max(getHeight(root->lchild),getHeight(root->rchild))+1;
} 

void L(Node* &root){
	Node* temp = root->rchild;
	root->rchild=temp->lchild;
	temp->lchild=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
}

void R(Node* &root){
	Node* temp = root->lchild;
	root->lchild=temp->rchild;
	temp->rchild=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
}

void insert(Node* &root, int v){
	if(root==NULL){
		root = newNode(v);
		return;
	}
	if(v < root->v){
		insert(root->lchild,v);
		updateHeight(root);
		if(getBF(root)==2){
			if(getBF(root->lchild)==1){
				R(root);
			}else if(getBF(root->lchild)==-1){
				L(root->lchild);
				R(root);
			} 
		}
	}else{
		insert(root->rchild,v);
		updateHeight(root);
		if(getBF(root)==-2){
			if(getBF(root->rchild)==-1){
				L(root);
			}else if(getBF(root->rchild)==1){
				R(root->rchild);
				L(root);
			} 
		}
	}
}

Node* Create(int data[],int n){
	Node* root = NULL;
	for(int i=0;i<n;i++){
		insert(root,data[i]);
	}
	return root;
}

bool flag=true;
bool over=false;
void BFS(Node* root){
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node* now = q.front();
		
		q.pop();
		if (now->lchild!=NULL)
		{
			if (over==true)
			{
				flag=false;
			}
			q.push(now->lchild);
		}else{
			if (over==false)
			{
				over=true;
			}
		}
		if (now->rchild!=NULL)
		{
			if (over==true)
			{
				flag=false;
			}
			q.push(now->rchild);
		}else{
			if (over==false)
			{
				over=true;
			}
		}
		printf("%d",now->v);
		if (!q.empty())
		{
			printf(" ");
		}
		else printf("\n");
	}
}

int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>a[i];
	}
	Node* root = Create(a,N);
	BFS(root);
	if (flag==true)
	{
		cout<<"YES";
	}else cout<<"NO";
}
