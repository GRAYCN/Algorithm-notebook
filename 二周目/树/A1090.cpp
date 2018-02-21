//A1079
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
#define maxn 100005
struct Node{
	vector<int> child;
	double amount;
}node[maxn];
int N;
double P,r;
double total;
int maxDepth=-1;
double maxTotal=-1;
int cnt=0;
void DFS(int root,int depth){
	if(node[root].child.size()==0){
		if(maxDepth<depth){
			maxDepth=depth;
			maxTotal=P*pow((100+r)/100,depth);
			cnt=1;
		}else if(maxDepth == depth){
			cnt++;
		}
		return;
	}
	for(int i=0;i<node[root].child.size();i++){
		DFS(node[root].child[i], depth+1);
	}
}
int main(){
	scanf("%d%lf%lf",&N,&P,&r);
	int root=-1;
	for(int i=0;i<N;i++){
		int father;
		scanf("%d",&father);
		if(father!=-1)
			node[father].child.push_back(i);
		else root=i;
	}
	DFS(root,0);
	printf("%.2f %d",maxTotal,cnt);
}
