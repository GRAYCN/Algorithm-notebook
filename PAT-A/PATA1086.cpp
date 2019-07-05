//PATA1086
//����������������У������������
#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
struct node {
	node* lchild;
	node* rchild;
	int data;
};
int N;
stack<int> s;
vector<int> pre,in;

node* create(int preL,int preR,int inL, int inR) {
	if(preL>preR) return NULL;
	node* root = new node;
	root->data=pre[preL];
	int k;
	for(k=inL; k<=inR; k++) {
		if(in[k] == pre[preL]) break;
	}
	int numLeft = k-inL;
	root->lchild=create(preL+1,preL+numLeft,inL,k-1);
	root->rchild=create(preL+numLeft+1,preR,k+1,inR);
	return root;
}
int num=0;
void DFS(node* root) {
	if(root ==NULL) return;
	if(root->lchild!=NULL) DFS(root->lchild);
	if(root->rchild!=NULL) DFS(root->rchild);
	cout<<root->data;
	num++;
	if(num!=N){
		cout<<" ";
	}
}

int main() {
	cin>>N;
	for(int i=0; i<2*N; i++) {
		string str;
		cin>>str;
		//�����push����Ҫ��������һλ���֣���������ּ��뵽pre[]������
		if(str=="Push") {
			int temp;
			cin>>temp;
			s.push(temp);
			pre.push_back(temp);
		}
		//�����Pop��ֱ�ӽ�s�е����鵯������������洢��in[]������
		else {
			int temp=s.top();
			s.pop();
			in.push_back(temp);
		}
	}
	node* root = create(0,N-1,0,N-1);

	DFS(root);
}
