#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
#define maxn 100
int m,n;
struct Node {
	int x,y;	//Œª÷√£®x,y)
	Node(){
	}
	Node(int _x, int _y){
		x=_x;
		y=_y;
	}
}S,T;
bool vis[maxn][maxn];
char matrix[maxn][maxn];
int X[4]={0,0,1,-1};
int Y[4]={1,-1,0,0};
int minDepth=999999;
void dfs(int row, int col,int depth){
	if(row<0 || row>=m || col<0 || col>=n) return; //‘ΩΩÁ 
	if(vis[row][col] || matrix[row][col]=='*') return;
	if(row==T.x && col==T.y){
		minDepth=min(minDepth,depth);
		return;
	}
	
	vis[row][col]=true;
	for(int i=0;i<4;i++){
		dfs(row+X[i],col+Y[i],depth+1);
	}
	vis[row][col]=false;
}
int cnt=0;
int main(){
	cin>>m>>n;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>matrix[i][j];
		}	
	}
	cin>>S.x>>S.y>>T.x>>T.y;
	dfs(S.x,S.y,0);
	printf("%d",minDepth);
}

/*
5 5
.....
.*.*.
.*S*.
.***.
...T*
2 2 4 3 
*/

