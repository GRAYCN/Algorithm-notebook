
/*----------------------------liuchuo-------------------------------------*/

//#include <iostream>
//#include <vector>
//#include <map>
//using namespace std;
//map<int, int> pos;
//vector<int> in, pre;
//void lca(int in_left, int in_right, int preRoot, int a, int b) {
//    if (in_left > in_right) return;
//    int inRoot = pos[pre[preRoot]], aIn = pos[a], bIn = pos[b];
//    if (aIn < inRoot && bIn < inRoot)
//        lca(in_left, inRoot - 1, preRoot + 1, a, b);
//    else if ((aIn < inRoot && bIn > inRoot) || (aIn > inRoot && bIn < inRoot))
//        printf("LCA of %d and %d is %d.\n", a, b, in[inRoot]);
//    else if (aIn > inRoot && bIn > inRoot)
//        lca(inRoot+1, in_right, preRoot + 1 + (inRoot - in_left), a, b);
//    else if (aIn == inRoot)
//        printf("%d is an ancestor of %d.\n", a, b);
//    else if (bIn == inRoot)
//        printf("%d is an ancestor of %d.\n", b, a);
//}
//int main() {
//    int m, n, a, b;
//    scanf("%d %d", &m, &n);
//    in.resize(n + 1), pre.resize(n + 1);
//    for (int i = 1; i <= n; i++) {
//        scanf("%d", &in[i]);
//        pos[in[i]] = i;
//    }
//    for (int i = 1; i <= n; i++) scanf("%d", &pre[i]);
//    for (int i = 0; i < m; i++) {
//        scanf("%d %d", &a, &b);
//        if (pos[a] == 0 && pos[b] == 0)
//            printf("ERROR: %d and %d are not found.\n", a, b);
//        else if (pos[a] == 0 || pos[b] == 0)
//            printf("ERROR: %d is not found.\n", pos[a] == 0 ? a : b);
//        else
//            lca(1, n, 1, a, b);
//    }
//    return 0;
//}



/*---------------------------------my own code-------------------------------------*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
vector<int> pre,in;
// vector<int> pathA,pathB;
struct Node{
    int data;
    Node* left, *right;
};

Node * getLCA(Node *root, int a, int b);

Node* newNode(int x){
    Node* node = new Node;
    node->data=x;
    node->left=node->right=NULL;
    return node;
}

Node* build(int preL, int preR, int inL, int inR){
    if(preL>preR){
        return NULL;
    }
    Node* root = newNode(pre[preL]);
    int k;
    for(k=inL;k<=inR;k++){
        if(in[k]==root->data){
            break;
        }
    }
    int numLeft=k-inL;
    root->left=build(preL+1,preL+numLeft,inL,k-1);
    root->right=build(preL+numLeft+1,preR,k+1,inR);
    return root;
}

void DFS(Node *root, int x, vector<int> &path){
    if(root->data==x){
        path.push_back(x);
        return;
    }
    path.push_back(root->data);
    if(x < root->data){
        DFS(root->left,x, path);
    }else{
        DFS(root->right,x, path);
    }
}

int main(int argc, char *argv[]) {
    int M,N;
    scanf("%d%d",&M,&N);
    pre.resize(N);
    in.resize(N);
//    pos.resize(N);
    unordered_map<int,int> pos;

    for(int i=0;i<N;i++){
        scanf("%d",&in[i]);
        pos[in[i]] = i;
    }
    for(int i=0;i<N;i++){
        scanf("%d",&pre[i]);
    }
    Node* root = build(0,N-1,0,N-1);

    while(M--){
        int a,b;
        scanf("%d%d",&a,&b);
        bool existA=true;
        bool existB=true;
        if(pos.find(a)==pos.end()){
            existA=false;
        }
        if(pos.find(b)==pos.end()){
            existB=false;
        }
        if(!existA && !existB){
            printf("ERROR: %d and %d are not found.\n",a,b);
            continue;
        }else if(!existA){
            printf("ERROR: %d is not found.\n",a);
            continue;
        }else if(!existB){
            printf("ERROR: %d is not found.\n",b);
            continue;
        }

        Node *pNode = getLCA(root, a, b);

        if(pNode->data==a){
            printf("%d is an ancestor of %d.\n",a,b);
            continue;
        }else if(pNode->data==b){
            printf("%d is an ancestor of %d.\n",b,a);
            continue;
        }else{
            printf("LCA of %d and %d is %d.\n",a,b,pNode->data);
            continue;
        }
    }

    return 0;
}

Node * getLCA(Node *root, int a, int b) {
    if(root== nullptr)
        return nullptr;
    if (root->data == a || root->data == b) {
        return root;
    }

    Node *left = getLCA(root->left, a, b);
    Node *right = getLCA(root->right, a, b);

    if (left != nullptr && right != nullptr) {
        return root;
    } else if (left != nullptr) {
        return left;
    } else if (right != nullptr) {
        return right;
    } else return nullptr;
}
