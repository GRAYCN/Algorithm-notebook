//PATA1091 17'
#include<cstdio>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;
int matrix[1286*60+5][130];
bool inq[1286*60+5][130];
int X[6]= {1,-1,0,0,0,0};
int Y[6]= {0,0,1,-1,0,0};
struct Node {
	int x,y;
	int value;
} node;

int M,N,L,T;		//矩阵使用M by N来表示
int ans;

judge(int x,int y){
	if(x<0 || x>(M-1)*(L-1) || y<0 || y> N-1) return false;
	if(matrix[x][y]==0 || inq[x][y]==true) return false;
	return true;
}

void BFS(int x,int y) {
	int temp=0;		//记录当前BFS遍历中1的总和
	queue<Node> q;
	node.x=x,node.y=y;
	q.push(node);
	inq[x][y]=true;
	while(!q.empty()) {
		Node top = q.front();
		q.pop();
		temp++;

		for(int i=0; i<6; i++) {		//循环6次，得到6个相邻位置
			int newX=top.x+X[i];
			int newY=top.y+Y[i];
			if(judge(newX,newY)) {
				node.x=newX,node.y=newY;
				q.push(node);
				inq[newX][newY]=true;
			}
		}
	}
	if(temp>=T) {
		ans+=temp;
		return;
	}
}

int main() {
	scanf("%d%d%d%d",&M,&N,&L,&T);
	X[4]=M;
	X[5]=-M;
	for(int i=0; i<M*L-1; i++) {
		for(int j=0; j<N; j++) {
			scanf("%d",&matrix[i][j]);
		}
	}
	for(int i=0; i<M*L-1; i++) {
		for(int j=0; j<N; j++) {
			if(matrix[i][j]==1 && inq[i][j] == false) {
				BFS(i,j);
			}
		}
	}
	cout<<ans<<endl;
}
