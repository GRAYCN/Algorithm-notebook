//A1020
#include<iostream>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

const int maxn = 40;
 
struct Node{
	Node* lchild, *rchild;
	int data;
};
int in[maxn];
vector<int> pre,post; 
vector<int> layer;

Node* newNode(int val){
	Node* node = new Node;
	node->data=val;
	node->lchild=node->rchild=NULL;
	return node;
}

void preOrder(Node* root)
{
    if(!root) return;
    pre.push_back(root->data);
    preOrder(root->lchild);
    preOrder(root->rchild);
}

void postOrder(Node* root)
{
    if(!root) return;
    postOrder(root->lchild);
    postOrder(root->rchild);
    post.push_back(root->data);
}

Node* build(vector<int> layer, int inL, int inR){
	if(layer.size()==0) return NULL;
	Node* root = new Node;
	root->data=layer[0];
	int k;
	for(k=inL;k<=inR;k++){
		if(in[k]==layer[0])
			break;
	}
	vector<int> leftLayer,rightLayer;
	for(int i=1;i<layer.size();i++){
		bool isLeft=false;
		for(int j=inL;j<k;j++){
			if(layer[i]==in[j]){
				isLeft=true;
				break;
			}
		}
		if(isLeft){
			leftLayer.push_back(layer[i]);
		}else{
			rightLayer.push_back(layer[i]);
		}
	}
	root->lchild=build(leftLayer,inL,k-1);
	root->rchild=build(rightLayer,k+1,inR);
	return root;
}

//Node* build(vector<int> layer, int inL, int inR){
//	if(layer.size()==0) return NULL;
//	Node* root = new Node;
//	root->data=layer[0];
//	int k;
//	for(k=inL;k<=inR;k++){
//		if(layer[0]==in[k])
//			break;
//	}
//	vector<int> leftLayer;
//	vector<int> rightLayer;
//	
//	for(int i=1;i<layer.size();i++){
//		bool isLeft = false;
//		for(int j=inL;j<k;j++){
//			if(layer[i]==in[j]){
//				isLeft=true;
//				break;
//			}
//		}
//		if(isLeft)
//			leftLayer.push_back(layer[i]);
//		else
//			rightLayer.push_back(layer[i]);
//	}
//	root->lchild=build(leftLayer,inL,k-1);		
//	root->rchild=build(rightLayer,k+1,inR);
//	return root;
//}

int main(){
	 int n;
    scanf("%d", &n);
    int temp;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        layer.push_back(temp); 
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &in[i]); 
    }

    Node* root = build(layer,0,n - 1);

    preOrder(root);
    postOrder(root);

    for(int i = 0; i < pre.size(); i++)
    {
        printf("%d", pre[i]);
        if(i < pre.size() - 1)
        {
            printf(" ");
        }
    }

    printf("\n");

    for(int i = 0; i < post.size(); i++)
    {
        printf("%d", post[i]);
        if(i < post.size() - 1)
        {
            printf(" ");
        }
    }

    printf("\n");
    return 0;
}

/*
7
4 1 6 3 5 7 2
1 2 3 4 5 6 7

*/ 
