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

void check(Node* root){
	if(root==NULL) return; 
	if(root->lchild==NULL && root->rchild==NULL){
		path.push_back(root);
		int cnt=0;
		for(int i=0;i<path.size();i++){
			Node* node = path[i];
			if(node->color=="black"){
				cnt++;
			}
		}
		numOfBlack.push_back(cnt);
		path.pop_back();
	}
	path.push_back(root);
	if(root->lchild!=NULL) check(root->lchild);
	if(root->rchild!=NULL) check(root->rchild);
	path.pop_back();
}

bool isSame(){
	/*if(numOfBlack.size()==0) return true;
	int x = numOfBlack[0];
	for(int i=1;i<numOfBlack.size();i++){
		if(numOfBlack[i]!=x){
			return false;
		}
	}
	return true;*/
	int temp=-1;
	int cnt=0;
	for (int i=0;i<numOfBlack.size();i++){
		if (numOfBlack[i]!=temp)
		{
			cnt++;
			temp=numOfBlack[i];
		}
	}
	if (cnt>=2)
	{
		return false;
	}
	return true;
}

void BFS(Node* root){
	queue<Node*> q;
	q.push(root);
	int cishu=0;
	while(!q.empty()){
		Node* now=q.front();
		cishu++;
		//printf("%d\n",cishu);
		q.pop();
		if(now->color=="red"){
			if( (now->lchild && now->lchild->color=="red") ||  (now->rchild && now->rchild->color=="red") ){		//问题出在这里，有可能左右子树为NULL
				flag=false;
				return;
			}
		}
		numOfBlack.clear();
		path.clear();
		check(now);
		if(!isSame()){
			flag=false;
			return;
		}
		if(now->lchild!=NULL) q.push(now->lchild);
		if(now->rchild!=NULL) q.push(now->rchild);
	}
}
int globalNumOfBlack=-1;
void DFS(Node* root, int numOfBlack){
	if(!flag) return;
	if(root==NULL){
		if(globalNumOfBlack==-1) numOfBlack=globalNumOfBlack;
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
			continue;
		}else{
			flag=true;
			DFS(root,0);
			if(flag==true){
				cout<<"Yes"<<endl;
			}else{
				cout<<"No"<<endl;
			}
		}
	}
}
