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
bool flag=true;
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

int globalNumOfBlack=-1;
void DFS(Node* root, int numOfBlack){
	if(!flag) return;
	if(root==NULL){
		if(globalNumOfBlack==-1) globalNumOfBlack=numOfBlack;
		else{
			if(numOfBlack!=globalNumOfBlack){
				flag=false;
			}
		}
		return;
	}
	if(root->color=="black") numOfBlack++;
	if(root->color=="red"){
		if(root->lchild && root->lchild->color=="red"){
			flag=false;
			return;
		}
		if(root->rchild && root->rchild->color=="red"){
			flag=false;
			return;
		}		
	}
	DFS(root->lchild,numOfBlack);
	DFS(root->rchild,numOfBlack);
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
//			continue;
		}else{
			flag=true;
			DFS(root,0);
			if(flag==true){
				cout<<"Yes\n";
			}else{
				cout<<"No\n";
			}
		}
	}
}
