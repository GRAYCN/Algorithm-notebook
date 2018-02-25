// PATA1135 21' 

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include <cmath>
#include <queue>
using namespace std;

struct Node{
	int data;
	string color;
	Node* lchild,*rchild;	
};
vector<int> pre,in;
vector<int> numOfBlack;
vector<Node*> path;

int num=0;
Node* build(int preL,int preR,int inL,int inR){

	if(preL>preR){
		return NULL;
	}
	Node* root=new Node;
	root->data = pre[preL];
	if (root->data<0)
	{
		root->data = -(root->data);
		root->color="red";
	}else{
		root->color="black";
	}
	int k;
	for(k=inL;k<=inR;k++){
		if(abs(in[k])==root->data){
			break;
		}
	}
	int numLeft=k-inL;
	root->lchild=build(preL+1,preL+numLeft,inL,k-1);
	root->rchild=build(preL+numLeft+1,preR,k+1,inR);
	return root;
}

int cmp(int a,int b){
	return abs(a)<abs(b);
}

bool flag;
int num_black;
int cnt=0;
void DFS(Node* root,int num){
	if(root==NULL || flag==false) return;
//	if(root->lchild==NULL && root->rchild==NULL){
	if(root==NULL){
		if(cnt==0){
			num_black=num;
			cnt++;
		}else{
			if(num_black!=num){
				flag=false;
				return;
			}
		}
	}
	if(root->color=="red"){
		if( (root->lchild && root->lchild->color=="red") ||  (root->rchild && root->rchild->color=="red") ){		//问题出在这里，有可能左右子树为NULL
			flag=false;
			return;
		}
	}
	int black= root->color=="black"?1:0;
	DFS(root->lchild,num+black);
	DFS(root->rchild,num+black);
} 

int main(){
	int K,N;
	cin>>K;
	for(int i=0;i<K;i++){
		cin>>N;
		pre.resize(N);
		in.resize(N);
		for(int j=0;j<N;j++){
			cin>>pre[j];
		}
		in=pre;
		sort(in.begin(),in.end(),cmp);
		Node* root = build(0,N-1,0,N-1);
		if(root->color=="red"){
			cout<<"No"<<endl;
			continue;
		}else{
			flag=true;
			num_black=0;
			DFS(root,0);
			if(flag==true){
				cout<<"Yes"<<endl;
			}else{
				cout<<"No"<<endl;
			}
		}
	}
}
