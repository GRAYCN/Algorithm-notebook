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

vector<int> v[maxn];
int layer[maxn];

int N,L;
bool inq[maxn];
int cnt;
void BFS(int index){
	queue<int> q;
	q.push(index);
	layer[index]=0;
	inq[index]=true;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		//		if(now.layer<=L){
		if (layer[now]>0)
		{
			cnt++;
		}
		//		}
		for(int i=0;i<v[now].size();i++){
			int next=v[now][i];
			if(!inq[next]){
				inq[next]=true;
//				node.data=next;
				layer[next]=layer[now]+1;
				if(layer[next]<=L){
					q.push(next);	
				}
			}
		}
	}

}

int main(){
	cin>>N>>L;
	for(int i=1;i<=N;i++){
		int M,user_id;
//		node.data=i;
		cin>>M;
		for(int j=0;j<M;j++){
			cin>>user_id;
			v[user_id].push_back(i);
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
