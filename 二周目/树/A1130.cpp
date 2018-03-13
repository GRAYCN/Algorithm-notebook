//A1130
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
#define maxn 25
struct Node{
	int lchild,rchild;
	string value;
}node[maxn];

int N;
int root=-1;
void inOrder(int index){
	if(index==-1) return;
	if( (node[index].lchild!=-1 || node[index].rchild!=-1) && index!=root ){
		cout<<"(";
	}
	inOrder(node[index].lchild);
	cout<<node[index].value;
	inOrder(node[index].rchild);
	if( (node[index].lchild!=-1 || node[index].rchild!=-1) && index!=root ){
		cout<<")";
	}
}

int main(){
	cin>>N;
	string value;
	bool isRoot[maxn];
	fill(isRoot,isRoot+maxn,true);
	int lchild,rchild;
	for(int i=1;i<=N;i++){
		cin>>node[i].value>>node[i].lchild>>node[i].rchild;
		if(node[i].lchild!=-1) isRoot[node[i].lchild]=false;
		if(node[i].rchild!=-1) isRoot[node[i].rchild]=false;
	}	
	
	for(int i=1;i<=N;i++){
		if(isRoot[i]==true){
			root=i;
			break;
		}
	}
	inOrder(root);
}
