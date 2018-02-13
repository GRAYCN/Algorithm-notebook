//PATA1079
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define maxn 100005

struct node {
//	int layer;			//记录每个结点的层数，根结点为0层
	vector<int> child;
	double amount;
} Node[maxn];

int n;
double p,r;

double ans;
void DFS(int index, int depth) {
	//到达叶子结点
	if(Node[index].child.size()==0) {
		double temp = p*pow((1+r),depth)*Node[index].amount;
		ans+=temp;
		return;
	}
	for(int i=0; i<Node[index].child.size(); i++) {
		DFS(Node[index].child[i],depth+1);
	}
}


int main() {
	int k,child;
	cin>>n>>p>>r;
	r/=100;
	for(int i=0; i<n; i++) {
		cin>>k;
		if(k==0) {
			cin>>Node[i].amount;
		} else {
			for(int j=0; j<k; j++) {
				cin>>child;
				Node[i].child.push_back(child);
			}
		}
	}
	DFS(0,0);
	printf("%.1f\n",ans);
}
