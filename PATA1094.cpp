	//PATA1094
	#include<iostream>
	#include<queue>
	#define maxn 105
	using namespace std; 
	struct node{
		vector<int> child;
		int layer;
	}Node[maxn];
	
	int count[maxn];		//用来记录每一层各有多少结点 
	void BFS(){
		queue<int> q;
		q.push(1);
		Node[1].layer=1;
		while(!q.empty()){
			int now = q.front();
			count[Node[now].layer]++;		
			q.pop();
			for(int i=0;i<Node[now].child.size();i++){
				int temp = Node[now].child[i];
				Node[temp].layer=Node[now].layer+1;
				q.push(temp);
			}
		}
	}
	int N,M; 
	int main(){
		cin>>N>>M;
		for(int i=0;i<M;i++){
			int index,num,child;
			cin>>index>>num;
			for(int j=0;j<num;j++){
				cin>>child;
				Node[index].child.push_back(child);
			}
		}
		BFS();
		int maxLayer=-1,maxNum=-1;
		for(int i=1;i<=N;i++){
			if(count[i]>maxNum){
				maxNum=count[i];
				maxLayer=i;
			}
		}
		cout<<maxNum<<" "<<maxLayer;
	}
