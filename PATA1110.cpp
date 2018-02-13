//PATA1110
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn= 25;
struct Node{
	int lchild,rchild,parent;
	Node(){
		lchild=rchild=parent=-1;
	}
}node[maxn];
int n,num=0;

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int lchild=-1,rchild=-1;
		scanf("%d",&lchild);
		scanf("%d",&rchild);
		node[i].lchild= lchild;
		node[i].rchild= rchild;
		node[lchild].parent=i;
		node[rchild].parent=i;
	}
	int root=0;
	int last=0;
	bool flag=false;
	while(node[root].parent!=-1) root=node[root].parent;
	//level traversal
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int p= q.front();
		if(p != -1){
			q.push(node[p].lchild);
			q.push(node[p].rchild);
			last=p;
			if(flag){
				printf("NO %d\n",root);
				return 0;
			}
		}else{
			flag= true;
		}
		q.pop();
	}
	printf("YES %d\n",last);
}
