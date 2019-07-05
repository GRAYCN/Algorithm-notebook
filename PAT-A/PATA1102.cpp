//PATA1102
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define maxn 100
struct node {		//二叉树的静态写法
	int lchild,rchild;
} Node[maxn];
bool notRoot[maxn];		//记录是否为根节点，初始均为根节点
int n,num=0;		//n为结点个数,num为当前已经输出的结点个数
//输出结点id的编号
void print(int id) {
	printf("%d",id);
	num++;
	if(num<n) printf(" ");
	else printf("\n");
}
//中序遍历
void inOrder(int root) {
	if(root == -1) {
		return;
	}
	inOrder(Node[root].lchild);
	print(root);
	inOrder(Node[root].rchild);
}

//层序遍历
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
//后序遍历，用来反转二叉树
void postOrder() {

}

//将输入的字符转换成-1或者结点编号
int strToNum(char c) {
	if(c=='-') return -1;		//-1表示没有孩子结点
	else {
		notRoot[c-'0']=true;
		return c-'0';
	}
}

//寻找根节点
int findRoot() {
	for(int i=0; i<n; i++) {
		if(notRoot[i]==false)
			return i;
	}
}
int main() {
	scanf("%d",&n); 		//结点个数
	for(int i=0; i<n; i++) {
		//思路：在获取输入的时候直接将二叉树进行逆置
		char l,r;
		getchar();
		scanf("%c %c",&l,&r);
		Node[i].lchild=strToNum(r);
		Node[i].rchild=strToNum(l);
	}
	int root = findRoot();
	BFS(root);		//输出层序遍历序列
	num=0;
	inOrder(root);
}
