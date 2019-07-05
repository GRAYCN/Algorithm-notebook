//PATA1102
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define maxn 100
struct node {		//�������ľ�̬д��
	int lchild,rchild;
} Node[maxn];
bool notRoot[maxn];		//��¼�Ƿ�Ϊ���ڵ㣬��ʼ��Ϊ���ڵ�
int n,num=0;		//nΪ������,numΪ��ǰ�Ѿ�����Ľ�����
//������id�ı��
void print(int id) {
	printf("%d",id);
	num++;
	if(num<n) printf(" ");
	else printf("\n");
}
//�������
void inOrder(int root) {
	if(root == -1) {
		return;
	}
	inOrder(Node[root].lchild);
	print(root);
	inOrder(Node[root].rchild);
}

//�������
void BFS(int root) {
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
		int now=q.front();
		q.pop();
		print(now);
		if(Node[now].lchild!=-1) q.push(Node[now].lchild);
		if(Node[now].rchild!=-1) q.push(Node[now].rchild);
	}
}
//���������������ת������
void postOrder() {

}

//��������ַ�ת����-1���߽����
int strToNum(char c) {
	if(c=='-') return -1;		//-1��ʾû�к��ӽ��
	else {
		notRoot[c-'0']=true;
		return c-'0';
	}
}

//Ѱ�Ҹ��ڵ�
int findRoot() {
	for(int i=0; i<n; i++) {
		if(notRoot[i]==false)
			return i;
	}
}
int main() {
	scanf("%d",&n); 		//������
	for(int i=0; i<n; i++) {
		//˼·���ڻ�ȡ�����ʱ��ֱ�ӽ���������������
		char l,r;
		getchar();
		scanf("%c %c",&l,&r);
		Node[i].lchild=strToNum(r);
		Node[i].rchild=strToNum(l);
	}
	int root = findRoot();
	BFS(root);		//��������������
	num=0;
	inOrder(root);
}
