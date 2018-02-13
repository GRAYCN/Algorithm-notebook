//PATA1004
#include<iostream>
#define maxn 105
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct node{
	vector<int> child;
	int layer;
}Node[maxn];
int count1[maxn];		//计算每一层叶子结点的个数 
int maxLayer;

void BFS(){
	queue<int> q;
	q.push(1);
	Node[1].layer=1;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		if(Node[now].child.size()==0){
			count1[Node[now].layer]++;
		}else{
			for(int i=0;i<Node[now].child.size();i++){
				int temp=Node[now].child[i];
				Node[temp].layer=Node[now].layer+1;
				maxLayer=max(maxLayer,Node[temp].layer);
				q.push(temp);
			}
		}
	}
}

int N,M;
int main(){
	cin>>N>>M;
	if (M==0)
	{
		cout<<1;
		return 0;
	}
	for(int i=0;i<M;i++){
		int index,num,child;
		cin>>index>>num;
		for(int j=0;j<num;j++){
			cin>>child;
			Node[index].child.push_back(child);
		}
	}
	BFS();
	for(int i=1;i<=maxLayer;i++){
		if(i!=1) cout<<" ";
		cout<<count1[i];
	}
}
