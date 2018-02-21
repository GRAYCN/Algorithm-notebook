//A1106
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
double minPrice=99999;
int minDepth=999999;
int cnt;
void DFS(int root,int depth){
	if(node[root].child.size()==0){
		if(depth<minDepth){
			minDepth=depth;
			minPrice=P*pow((100+r)/100,depth);
			cnt=1;
		}else if(depth==minDepth){
			cnt++;
		}
	}
	
	for(int i=0;i<node[root].child.size();i++){
		DFS(node[root].child[i], depth+1);
	}
}
int main(){
	scanf("%d%lf%lf",&N,&P,&r);
	for(int i=0;i<N;i++){
		int K;
		scanf("%d",&K);
		int child;
		for(int j=0;j<K;j++){
			scanf("%d",&child);
			node[i].child.push_back(child);
		}
	}
	DFS(0,0);
	printf("%.4f %d",minPrice,cnt);
}
