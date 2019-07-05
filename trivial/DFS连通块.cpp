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
} node;
bool vis[maxn][maxn];
int matrix[maxn][maxn];
int X[4]={0,0,1,-1};
int Y[4]={1,-1,0,0};
void dfs(int row, int col){
	if(row<0 || row>=m || col<0 || col>=n) return; //‘ΩΩÁ 
	if(vis[row][col] ||matrix[row][col]!=1) return;
	vis[row][col]=true;
	for(int i=0;i<4;i++){
		dfs(row+X[i],col+Y[i]);
	}
}
int cnt=0;
int main(){
	cin>>m>>n;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>matrix[i][j];
		}	
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(!vis[i][j] && matrix[i][j]==1){
				dfs(i,j);
				cnt++;
			}
		}	
	}
	printf("%d",cnt);
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

