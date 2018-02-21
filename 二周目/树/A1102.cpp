#include<iostream>
#include<cstring>
#include <string>
#include<algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct Node{
	int lchild, rchild;
	int data;
}node[15];
bool isRoot[15];
vector<int> in;

void BFS(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		if(node[now].lchild!=-1) q.push(node[now].lchild);
		if(node[now].rchild!=-1) q.push(node[now].rchild);
		printf("%d",now);
		if(!q.empty()){
			printf(" ");
		}
	}
}

void inOrder(int root){
	if(root==-1){
		return;
	}
	inOrder(node[root].lchild);
	in.push_back(root);
	inOrder(node[root].rchild);
}

int main(){
	int N;
	scanf("%d",&N);
	fill(isRoot,isRoot+10,true);
	for(int i=0;i<N;i++){
		char a,b;
		getchar();			//ÄÜ·ñ¼æÈÝ£¿ 
		scanf("%c %c",&a,&b);
		node[i].rchild= (a=='-'? -1:a-'0');
		node[i].lchild= (b=='-'? -1:b-'0');
		if(node[i].lchild!=-1){
			isRoot[node[i].lchild]=false;
		}
		if(node[i].rchild!=-1){
			isRoot[node[i].rchild]=false;
		}
	}
	int root=-1;
	for(int i=0;i<N;i++){
		if(isRoot[i]){
			root=i;
			break;
		} 
	}
	BFS(root);
	printf("\n");
	inOrder(root);
	for (int i=0;i<in.size();i++)
	{
		printf("%d",in[i]);
		if (i!=in.size()-1)
		{
			printf(" ");
		}
	}
}
