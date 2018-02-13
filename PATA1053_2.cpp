//PATA1053_2
//将例题中通过数组保存路径的方式修改为通过vector来存储 
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define maxn 110
struct node {
	int weight;
	vector<int> child;
} Node[maxn];

bool cmp(int a,int b) {
	return Node[a].weight>Node[b].weight;
}

int n,m,S;		//结点数，边数，给定和和
int path[maxn];
vector<int> v;


void DFS(int index, int sum) {
	if(sum>S) return;
	if(sum==S) {
		if(Node[index].child.size() != 0) return;		//当前还没有到达叶子结点，直接返回
		//剩下的都是到达叶子结点的

		for(int i=0; i<v.size(); i++) {
			cout<<Node[v[i]].weight;
			if(i<v.size()-1) cout<<" ";
			else cout<<endl;
		}
//		v.pop_back();
		return;		//返回，这一步很重要
	}

	for(int i=0; i<Node[index].child.size(); i++) {
		int child = Node[index].child[i];
//	path[numNode]  =child;
		v.push_back(child);
		DFS(child, sum+Node[child].weight);
		v.pop_back();
	}
//	v.pop_back();

}
int main() {
	cin>>n>>m>>S;
	for(int i=0; i<n; i++) {
		cin>>Node[i].weight;
	}
	int id,k,child;
	for(int i=0; i<m; i++) {
		cin>>id>>k;
		for(int j=0; j<k; j++) {
			cin>>child;
			Node[id].child.push_back(child);
		}
		//对叶子进行排序
		sort(Node[id].child.begin(),Node[id].child.end(),cmp);
	}
	path[0]=0;		//路径的第一个结点设置为0号结点
	v.push_back(0);
	DFS(0,Node[0].weight);	//DFS求解
}
