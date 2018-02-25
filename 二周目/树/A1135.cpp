//A1138 	静态方式 不知为何，使用静态方式总是会出错，这样的话以后碰到类似的建树问题还是使用动态方式为宜 
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
	int lchild, rchild;
}node[maxn];
int pre[maxn],in[maxn];
vector<int> post;

int build(int preL, int preR, int inL, int inR){
	if(preL>preR) return -1;
	int root = preL;
	int k=inL;
	for(;k<=inR;k++){
		if(in[k]== root)
			break;
	}
	int numLeft=k-inL;
	node[root].lchild=build(preL+1,preL+numLeft,inL,k-1);
	node[root].rchild=build(preL+numLeft+1,preR,k+1,inR);
	return root;
}

bool flag=false;

void postOrder(int root){
	if(!root || flag==true) return;		//equal to  root!=-1
	postOrder(node[root].lchild);
	postOrder(node[root].rchild);
//	post.push_back(root);
	if(flag == false){
		printf("%d",root);
		flag=true;
	}
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
	int root = build(0,N-1,0,N-1);
	postOrder(root);
	printf("%d",post[0]);
}
