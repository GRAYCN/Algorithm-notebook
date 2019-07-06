
//PATA1043
#include<iostream>
#include<vector>

using namespace std;
struct node {
    int data;
    node *left, *right;
};

void insert(node *&root, int data) {
    if (root == NULL) {
        root = new node;
        root->data = data;
        root->left = root->right = NULL;
        return;
    }
    if (data < root->data) insert(root->left, data);
    else insert(root->right, data);
}
vector<int> origin, pre, preM, post, postM;

void preOrder(node *root) {
    if (root == NULL) return;
    pre.push_back(root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node *root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    post.push_back(root->data);
}

void preOrderM(node *root) {
    if (root == NULL) return;
    preM.push_back(root->data);
    preOrderM(root->right);
    preOrderM(root->left);
}

void postOrderM(node *root) {
    if (root == NULL) return;
    postOrderM(root->right);
    postOrderM(root->left);
    postM.push_back(root->data);
}


int main() {
    int n, data;
    node *root = NULL;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> data;
        origin.push_back(data);
        insert(root, data);
    }
    preOrder(root);            //������
    preOrderM(root);        //����������
    postOrder(root);
    postOrderM(root);

    if (origin == pre) {
        cout << "YES" << endl;
        for (int i = 0; i < post.size(); i++) {
            cout << post[i];
            if (i != post.size() - 1) cout << " ";
        }
    } else if (origin == preM) {
        cout << "YES" << endl;
        for (int i = 0; i < postM.size(); i++) {
            cout << postM[i];
            if (i != postM.size() - 1) cout << " ";
        }
    } else {
        cout << "NO" << endl;
    }
}
