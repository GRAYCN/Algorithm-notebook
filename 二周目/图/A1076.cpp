#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
#define maxn 1005
struct Node{
	int layer;
	int data;
}node;

vector<Node> v[maxn];

int N,L;
bool inq[maxn];
int cnt;
void BFS(int index){
	queue<Node> q;
	node.data=index;
	node.layer=0;
	q.push(node);
	inq[index]=true;
	while(!q.empty()){
		Node now=q.front();
		q.pop();
		//		if(now.layer<=L){
		if (now.layer>0)
		{
			cnt++;
		}
		//		}
		for(int i=0;i<v[now.data].size();i++){
			int next=v[now.data][i].data;
			if(!inq[next]){
				inq[next]=true;
				node.data=next;
				node.layer=now.layer+1;
				if(node.layer<=L){
					q.push(node);	
				}
			}
		}
	}

}

int main(){
	cin>>N>>L;
	for(int i=1;i<=N;i++){
		int M,user_id;
		node.data=i;
		cin>>M;
		for(int j=0;j<M;j++){
			cin>>user_id;
			v[user_id].push_back(node);
		}
	}
	int K;
	cin>>K;
	for(int i=0;i<K;i++){
		int query;
		cin>>query;
		fill(inq,inq+maxn,false);
		cnt=0;
		BFS(query);	
		cout<<cnt<<endl;	
	}

} 
