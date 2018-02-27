//
//  A1043


#include <iostream>
#include <vector>
using namespace std;
struct Node{
	Node* lchild, *rchild;
	int data;
};
vector<int> input,pre,post;

Node* newNode(int x){
	Node* root = new Node;
	root->data=x;
	root->lchild=root->rchild=NULL;
	return root;
}

void insert(Node* &root,int x){
	if (root==NULL) {
		root=newNode(x);
		return;
	}
	if (x<root->data) {
		insert(root->lchild,x);
	}else{
		insert(root->rchild, x);
	}
}

void insertM(Node* &root,int x){
	if (root==NULL) {
		root=newNode(x);
		return;
	}
	if (x<root->data) {
		insertM(root->rchild,x);
	}else{
		insertM(root->lchild, x);
	}
}

void preOrder(Node* root){
	if (root==NULL) {
		return;
	}
	pre.push_back(root->data);
	preOrder(root->lchild);
	preOrder(root->rchild);
}

void postOrder(Node* root){
	if (root==NULL) {
		return;
	}
	postOrder(root->lchild);
	postOrder(root->rchild);
	post.push_back(root->data);
}

int main(int argc, const char * argv[]) {
	int N;
	cin>>N;
	Node* root=NULL,*rootM=NULL;
	input.resize(N);
	for(int i=0;i<N;i++){
		cin>>input[i];
		insert(root,input[i]);
		insertM(rootM, input[i]);
	}
	preOrder(root);
	if (pre==input) {
		cout<<"YES"<<endl;
		postOrder(root);
		for(int i=0;i<N;i++){
			cout<<post[i];
			if(i!=N-1){
				cout<<" ";
			}
		}
		return 0;
	}
	pre.clear();
	preOrder(rootM);
	if (pre==input) {
		cout<<"YES"<<endl;
		postOrder(rootM);
		for(int i=0;i<N;i++){
			cout<<post[i];
			if(i!=N-1){
				cout<<" ";
			}
		}
		return 0;
	}
	cout<<"NO"<<endl;
	return 0;

}

