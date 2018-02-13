//PATA1053_2
//��������ͨ�����鱣��·���ķ�ʽ�޸�Ϊͨ��vector���洢 
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

int n,m,S;		//������������������ͺ�
int path[maxn];
vector<int> v;


void DFS(int index, int sum) {
	if(sum>S) return;
	if(sum==S) {
		if(Node[index].child.size() != 0) return;		//��ǰ��û�е���Ҷ�ӽ�㣬ֱ�ӷ���
		//ʣ�µĶ��ǵ���Ҷ�ӽ���

		for(int i=0; i<v.size(); i++) {
			cout<<Node[v[i]].weight;
			if(i<v.size()-1) cout<<" ";
			else cout<<endl;
		}
//		v.pop_back();
		return;		//���أ���һ������Ҫ
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
		//��Ҷ�ӽ�������
		sort(Node[id].child.begin(),Node[id].child.end(),cmp);
	}
	path[0]=0;		//·���ĵ�һ���������Ϊ0�Ž��
	v.push_back(0);
	DFS(0,Node[0].weight);	//DFS���
}
