//PATA1130
#include<iostream>
#include<string>
using namespace std;
struct Node{
	int lchild,rchild;
	string data;
}node[25];
bool isRoot[25]={true};

void inorder(int root){
	if(root==-1){
		return;
	}
	inorder(node[root].lchild);
	cout<<node[root].data;
	inorder(node[root].rchild);
}

int main(){
	int N;
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>node[i].data>>node[i].lchild>>node[i].rchild;
		if(node[i].lchild!=-1) isRoot[node[i].lchild]=false;
		if(node[i].rchild!=-1) isRoot[node[i].rchild]=false;
	}
	int root;
	for(int i=1;i<=N;i++){
		if(isRoot[i]==true){
			root=i;
			break;
		}
	}
	inorder(root);
}
