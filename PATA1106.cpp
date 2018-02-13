//PATA1106
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define maxn 100005

struct node {
//	int layer;			//记录每个结点的层数，根结点为0层
	vector<int> child;
} Node[maxn];

int n;
double p,r;

int minDepth=maxn;
int num;
double minValue=0;
//目的是找到最浅的深度 
void DFS(int index, int depth) {
	//到达叶子结点
	if(Node[index].child.size()==0) {
//		double temp = p*pow((1+r),depth)*Node[index].amount;
//		ans+=temp;
		if(depth<minDepth){
			minDepth=depth;
			num=1;
			minValue=p*pow((1+r),depth);
		}else if(depth==minDepth){
			num++;
		} 
		return;
	}
	for(int i=0; i<Node[index].child.size(); i++) {
		DFS(Node[index].child[i],depth+1);
	}
}


int main() {
	int father;
	int root;
	cin>>n>>p>>r;
	r/=100;
	for(int i=0; i<n; i++) {
		int num,son;
		cin>>num;
		for(int j=0;j<num;j++){
			cin>>son;
			Node[i].child.push_back(son);
		}
	}
	DFS(0,0);
	printf("%.4f %d",minValue,num);
}
