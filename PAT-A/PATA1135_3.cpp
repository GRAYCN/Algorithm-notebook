//PATA1135_2
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include <cmath>
#include <queue>

using namespace std;

//struct Tree{
//	int data;
//	Tree *left;
//	Tree *right;
//	Tree(int d):data(d){}
//};

struct Node{
	int data;
	string color;
	Node* lchild,*rchild;	
};

vector<int> pre,in;

Tree* buildTree(int preL,int preR){
	if(preL>preR)
		return NULL;
	Tree *tree = new Tree(pre[preL]);
	int i = preL+1;
	for(;i<=preR;++i){
		if(abs(pre[i])>abs(pre[preL])){
			break;
		}
	}
	tree->left = buildTree(preL+1,i-1);
	tree->right = buildTree(i,preR);
	return tree;
}

bool flag,first;		//	需要通过两个Bool来实现所要实现的目的 
int num;

// 其实运用的是DFS的思路 
void judge(Node *node, bool isRedroot, int num_blacknodes){
	if(flag==false) return;
	if(node==NULL){
		if(first){			//第一次到达根节点 
			num = num_blacknodes;	//记录下一路上黑色叶子结点的数目 
			first = false;			//将first在本轮永久置为false 
		}else{
			if(num!=num_blacknodes){
				flag = false;		//如果不是第一次到达根节点，并且新的路径上的黑色结点数目与原先不等，那么将flag置为false 
			}
		}
	}else{				//如果是非叶子结点 
		bool isBlack = node->color=="black";	
		if(isRedroot&&!isBlack){	//如果父节点是红色，而当前节点也是红色，那么就不是红黑树 
			flag = false;
		}
		judge(node->lchild,!isBlack,num_blacknodes+isBlack);
		judge(node->rchild,!isBlack,num_blacknodes+isBlack);
	}
}

Node* build(int preL,int preR,int inL,int inR){

	if(preL>preR){
		return NULL;
	}
	Node* root=new Node;
	root->data = pre[preL];
	if (root->data<0)
	{
		root->data = -(root->data);
		root->color="red";
	}else{
		root->color="black";
	}
	int k;
	for(k=inL;k<=inR;k++){
		if(abs(in[k])==root->data){
			break;
		}
	}
	int numLeft=k-inL;
	root->lchild=build(preL+1,preL+numLeft,inL,k-1);
	root->rchild=build(preL+numLeft+1,preR,k+1,inR);
	return root;
}

int cmp(int a,int b){
	return abs(a)<abs(b);
}

int main()
{
	int K;
	cin >> K;
	for (int i = 0; i < K; ++i)
	{
		int N;
		cin >> N;
		pre.resize(N);
		in.resize(N);
		flag = first = true;
		num = 0;
		for (int j = 0; j < N; ++j)
		{
			cin >> pre[j];
		}
		in=pre;
		sort(in.begin(),in.end(),cmp);
//		Tree *tree = buildTree(0,N-1);
		Node *root = build(0,N-1,0,N-1);
		if(root->color=="red"){
			flag = false;
		}else{
			judge(root,false,0);
		}
		cout << (flag?"Yes":"No") << endl;
	}
	return 0;
}
