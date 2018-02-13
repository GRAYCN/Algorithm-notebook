//PATA1127
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
#define maxn 10000
int in[maxn],post[maxn];
struct Node{
	int lchild,rchild;
	int data;
	int layer;
}nodee[maxn];

int build(int inL,int inR,int postL,int postR){
	int root = post[postR];
	if(postL>postR)
		return -1;
	//else if(postL==postR){
	//	return root;
	//}
	int index;
	for(index=inL;index<=inR;index++){
		if(in[index]==post[postR])
			break;
	}
	int numLeft=index-inL;
	nodee[root].lchild=build(inL,index-1,postL,postL+numLeft-1);
	nodee[root].rchild=build(index+1,inR,postL+numLeft,postR-1);
	return root;
}

void DFS(int root){
	queue<int> q;
	stack<int> s;
	nodee[root].layer=1;
	q.push(root);
	s.push(root);
	while(!q.empty()){
		int now = q.front();
		q.pop();

		if(nodee[now].lchild!=-1){
			int index=nodee[now].lchild;
			nodee[index].layer=nodee[now].layer+1;
			q.push(index);
			if(nodee[index].layer%2==1){
				s.push(index);
			}
		}
		if(nodee[now].rchild!=-1){
			int index=nodee[now].rchild;
			nodee[index].layer=nodee[now].layer+1;
			q.push(index);
			if(nodee[index].layer%2==1){
				s.push(index);
			}
		}
		if(nodee[now].layer%2==0){
			cout<<now;
			if(!q.empty()) cout<<" ";
		}
		else{		//node[now].layer%2==1
			int temp = s.top();
			s.pop();
			cout<<temp;
			if(!q.empty()) cout<<" ";
		}
	}
}

int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>in[i];
	}
	for(int i=0;i<N;i++){
		cin>>post[i];
	}		
	int root = build(0,N-1,0,N-1);
	DFS(root);
} 
