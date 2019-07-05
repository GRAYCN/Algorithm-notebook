//PATA1099
#include<iostream>
#include<queue>
#include <algorithm>
#include<vector>
using namespace std;
#define maxn 105
struct node{
	int lchild,rchild;
	int data;
}Node[maxn];
vector<int> v,u;
int N;
int index=0;
void inOrder(int root){
	if(root==-1) return;
	inOrder(Node[root].lchild);
	Node[root].data=v[index++];
	//cout<<Node[root].data<<endl;
	inOrder(Node[root].rchild);
} 

void BFS(){
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		u.push_back(Node[now].data);
		//cout<<Node[now].data<<endl;
		if(Node[now].lchild!=-1) q.push(Node[now].lchild);
		if(Node[now].rchild!=-1) q.push(Node[now].rchild);
	}
}

int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		int lchild,rchild;
		cin>>lchild>>rchild;
		Node[i].lchild=lchild;
		Node[i].rchild=rchild;
		//node temp = Node[i];
		//cout<<endl;
	}
	for(int i=0;i<N;i++){
		int data;
		cin>>data;
		v.push_back(data);
	}
	sort(v.begin(),v.end());
	inOrder(0);
	BFS();
	for(int i=0;i<u.size();i++){
		cout<<u[i];
		if(i!=u.size()-1)
			cout<<" ";
	}
}
