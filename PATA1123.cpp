//PATA1113
//29' ==
#include<iostream>
#include<queue>
using namespace std;
struct Node{
	Node* lchild, *rchild;
	int data;
	int height;	
};

Node* newNode(int x){
	Node* root = new Node;
	root->lchild=root->rchild=NULL;
	root->data=x;
	return root;
}

void L(Node* &root){
	Node* temp = root->rchild;
	root->rchild=temp->lchild;
	temp->lchild=root;
	root=temp;
}

void R(Node* &root){
	Node* temp = root->lchild;
	root->lchild=temp->rchild;
	temp->rchild=root;
	root=temp;
}

int getHeight(Node* root){
	if(root==NULL) return 0;
	else{
		return max(getHeight(root->lchild),getHeight(root->rchild))+1;
	}
}

int getBF(Node* root){
	return getHeight(root->lchild)-getHeight(root->rchild);
}

void insert(Node* &root, int x){
	if(root==NULL){
		root=newNode(x);
		return;
	}
	if(x<root->data){
		insert(root->lchild,x);
		if (getBF(root)==2)
		{
			if(getBF(root->lchild)==1)  //LL
				R(root);
			else if(getBF(root->lchild)==-1)  //LR
			{
				L(root->lchild);
				R(root);
			}
		}
	}else{
		insert(root->rchild,x);
		if (getBF(root)==-2)
		{
			if(getBF(root->rchild)==-1)  //RR
				L(root);
			else if(getBF(root->rchild)==1)  //LR
			{
				R(root->rchild);
				L(root);
			}
		}
	}
}

bool leaf;
bool flag=true;

void BFS(Node* root){
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node* now = q.front();
		q.pop();
		cout<<now->data;
		if(now->lchild!=NULL){
			q.push(now->lchild);
			if(leaf==true)
				flag=false;
		}
		if(now->rchild!=NULL){
			q.push(now->rchild);
			if(leaf==true)
				flag=false;
		}
		if(now->lchild==NULL || now->rchild==NULL){
			leaf=true;
		}
		
		if(!q.empty()){
			cout<<" ";
		}
	}
}

int main(){
	int N;
	cin>>N;
	Node* root = NULL;
	for(int i=0;i<N;i++){
		int temp;
		cin>>temp;
		insert(root,temp);
	}
	BFS(root);
	cout<<endl;
	if(flag)
		cout<<"YES";
	else cout<<"NO";
}
