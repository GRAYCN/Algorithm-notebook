//A1065
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
using namespace std;

struct Node{
    Node* lchild, *rchild;
    int data;
};

void L(Node* &root){
    Node* temp=root->rchild;
    root->rchild=temp->lchild;
    temp->lchild=root;
    root=temp;
}

void R(Node* &root){
    Node* temp=root->lchild;
    root->lchild=temp->rchild;
    temp->rchild=root;
    root=temp;
}

int getHeight(Node* &root){
    if(root==NULL) return 0;
    return max(getHeight(root->lchild),getHeight(root->rchild))+1;
}

Node* newNode(int x){
    Node* root = new Node;
    root->data=x;
    root->lchild=root->rchild=NULL;
    return root;
}

int getBF(Node* root){
    if(root==NULL) return 0;
    return getHeight(root->lchild)-getHeight(root->rchild);
}

void insert(Node* &root, int x){
    if(root==NULL){
        root=newNode(x);
        return;
    }
    if(x<root->data){
        insert(root->lchild,x);
        if(getBF(root)==2){
            if(getBF(root->lchild)==1)
                R(root);
            else if(getBF(root->lchild)==-1){
                L(root->lchild);
                R(root);
            }
        }
    }else{
        insert(root->rchild,x);
        if(getBF(root)==-2){
            if(getBF(root->rchild)==-1)
                L(root);
            else if(getBF(root->rchild)==1){
                R(root->rchild);
                L(root);
            }
        }
    }
}

int main(){
    int N;
    cin>>N;
    Node* root=NULL;
    for(int i=0;i<N;i++){
        int num;
        cin>>num;
        insert(root,num);
    }
    cout<<root->data;
}