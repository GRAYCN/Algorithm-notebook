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

bool flag,first;		//	��Ҫͨ������Bool��ʵ����Ҫʵ�ֵ�Ŀ�� 
int num;

// ��ʵ���õ���DFS��˼· 
void judge(Node *node, bool isRedroot, int num_blacknodes){
	if(flag==false) return;
	if(node==NULL){
		if(first){			//��һ�ε�����ڵ� 
			num = num_blacknodes;	//��¼��һ·�Ϻ�ɫҶ�ӽ�����Ŀ 
			first = false;			//��first�ڱ���������Ϊfalse 
		}else{
			if(num!=num_blacknodes){
				flag = false;		//������ǵ�һ�ε�����ڵ㣬�����µ�·���ϵĺ�ɫ�����Ŀ��ԭ�Ȳ��ȣ���ô��flag��Ϊfalse 
			}
		}
	}else{				//����Ƿ�Ҷ�ӽ�� 
		bool isBlack = node->color=="black";	
		if(isRedroot&&!isBlack){	//������ڵ��Ǻ�ɫ������ǰ�ڵ�Ҳ�Ǻ�ɫ����ô�Ͳ��Ǻ���� 
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
