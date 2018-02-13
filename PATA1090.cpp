//PATA1090
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define maxn 100005

struct node {
//	int layer;			//��¼ÿ�����Ĳ����������Ϊ0��
	vector<int> child;
} Node[maxn];

int n;
double p,r;

int maxDepth=-1;
int num;
double maxValue=0;
//Ŀ�����ҵ��������� 
void DFS(int index, int depth) {
	//����Ҷ�ӽ��
	if(Node[index].child.size()==0) {
//		double temp = p*pow((1+r),depth)*Node[index].amount;
//		ans+=temp;
		if(depth>maxDepth){
			maxDepth=depth;
			num=1;
			maxValue=p*pow((1+r),depth);
		}else if(depth==maxDepth){
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
		cin>>father;
		if(father == -1){
			root=i;
		}else
			Node[father].child.push_back(i);
	}
	DFS(root,0);
	printf("%.2f %d",maxValue,num);
}
