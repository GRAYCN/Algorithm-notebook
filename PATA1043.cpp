
//PATA1043
#include<iostream>
#include<vector>
using namespace std;
struct node {
	int data;
	node *left,*right;
};

void insert(node* &root, int data) {
	if(root == NULL) {
		root=new node;
		root->data=data;
		root->left=root->right=NULL;
		return;
	}
	if(data<root->data) insert(root->left,data);
	else insert(root->right,data);
}

void preOrder(node* root,vector<int>& vi) {
	if(root==NULL) return;
	vi.push_back(root->data);
	preOrder(root->left,vi);
	preOrder(root->right,vi);
}

void preOrderM(node* root,vector<int>& vi) {
	if(root==NULL) return;
	vi.push_back(root->data);
	preOrderM(root->right,vi);
	preOrderM(root->left,vi);
}

void postOrder(node* root,vector<int>& vi) {
	if(root==NULL) return;
	postOrder(root->left,vi);
	postOrder(root->right,vi);
	vi.push_back(root->data);
}

void postOrderM(node* root,vector<int>& vi) {
	if(root==NULL) return;
	postOrderM(root->right,vi);
	postOrderM(root->left,vi);
	vi.push_back(root->data);
}

vector<int> origin, pre,preM, post,postM;
int main() {
	int  n,data;
	node* root = NULL;
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>data;
		origin.push_back(data);
		insert(root,data);
	}
	preOrder(root,pre);			//求先序
	preOrderM(root,preM);		//求镜像树先序
	postOrder(root,post);
	postOrderM(root,postM);

	if(origin == pre) {
		cout<<"YES"<<endl;
		for(int i=0; i<post.size(); i++) {
			cout<<post[i];
			if(i!=post.size()-1) cout<<" ";
		}
	} else if(origin==preM) {
		cout<<"YES"<<endl;
		for(int i=0; i<postM.size(); i++) {
			cout<<postM[i];
			if(i!=postM.size()-1) cout<<" ";
		}
	} else {
		cout<<"NO"<<endl;
	}
}
