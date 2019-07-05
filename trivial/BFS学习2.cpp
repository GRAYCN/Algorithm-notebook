#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
#define maxn 100
struct Node {
	int x,y;	//λ�ã�x,y)
	int step; 
	Node(){
	}
	Node(int _x, int _y){
		x=_x;
		y=_y;
	}
} node,T;

int n,m;
int matrix[maxn][maxn];
bool inq[maxn][maxn];
int X[4] = {0,0,-1,1};
int Y[4] = {1,-1,0,0};

bool judge(int x,int y){
	if(x>=n || x<0 || y>=m || y<0 ) return false;
	if(inq[x][y]==true || matrix[x][y]=='*') return false;
	return true;
}

int BFS(int x, int y){
	queue<Node> q;
	node.x=x;
	node.y=y;
	node.step=1;
	q.push(node);
	inq[x][y]=true;
	while(!q.empty()){
		Node now = q.front();
		if(now.x=T.x && now.y=T.y ) return now.step;
		q.pop();
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if(judge(now.x+X[i],now.y+Y[i])){
					node.x=now.x+X[i];
					node.y=now.y+Y[i];
					node.step=now.step+1;
					q.push(node);
					inq[now.x+X[i]][now.y+Y[i]]=true;		//don't forget here.
				}
			}
		}
	}
	return -1;	
}

int main(){
	cin>>n>>m;
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			cin>>matrix[x][y];
		}
	}
	int cnt=0;
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			if(!inq[x][y] && matrix[x][y]==1){
				BFS(x,y);
				cnt++;
			}
		}
	}
	cout<<cnt;
}

/*
6 7
0 1 1 1 0 0 1
0 0 1 0 0 0 0
0 0 0 0 1 0 0
0 0 0 1 1 1 0
1 1 1 0 1 0 0
1 1 1 1 0 0 0
*/

