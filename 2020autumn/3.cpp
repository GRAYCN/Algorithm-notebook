//
// Created by w on 2020/11/10.
//

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int maxn = 25;

struct node {
    int data;
    node* l;
    node* r;
    int layer;
};

int pre[maxn],in[maxn];
int n;
vector<int> res;

node* create(int preL, int preR, int inL, int inR) {
    if(preL>preR) return NULL;

    node *root = new node;
    root->data = pre[preL];
    int k;
    for(k=inL;k<=inR;k++) {
        if(in[k]==pre[preL]) break;
    }
    int numLeft = k-inL;

    root->l = create(preL+1, preL+numLeft, inL, k-1);
    root->r = create(preL+numLeft+1,preR,k+1,inR);

    return root;
}

int cnt=1;

void BFS(node *root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node *now =q.front();
        if(now->layer==cnt){
            cnt++;
            res.push_back(now->data);
        }
        q.pop();
        if(now->l != NULL){
            now->l->layer=now->layer+1;
            q.push(now->l);
        }
        if(now->r != NULL)
        {
            now->r->layer=now->layer+1;
            q.push(now->r);
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &in[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d", &pre[i]);
    }
    node *root = create(0,n-1,0,n-1);
    root->layer = 1;

    BFS(root);

    for(int i=0;i<res.size();i++){
        if(i>0) printf(" ");
        printf("%d", res[i]);
    }

    return 0;
}