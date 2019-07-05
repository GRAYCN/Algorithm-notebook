//PATA1119 
//PATA1119 
#include <cstdio>
int pre[32];
int post[32];
struct Node
{
	int l, r;
	Node(): l(-1), r(-1) {}
};
Node t[10000];
bool flag = true;
int build(int preL, int preR, int postL, int postR)
{
	int root = pre[preL];
	if (preL > preR) {
		return -1;
	} 
	else if (preL == preR) {
		return root;
	}
	int idx = 0;
	for(idx = preL + 1; idx <= preR; ++idx) {
		if (pre[idx] == post[postR-1]) break;
	}
	if (idx - preL > 1) { // 正常
		t[root].l = build(preL+1,idx-1,postL,postL+idx-preL-2);
		t[root].r = build(idx,preR,postL+idx-preL-1,postR-1);

	} else { // 出现歧义
		flag = false;
		t[root].l = build(preL+1,preR,postL,postR-1);
	}
	return root;
}
bool start = true;
void inorder(int root)
{
	if (root != -1) {
		inorder(t[root].l);
		if (!start) printf(" ");
		printf("%d", root);
		start = false;
		inorder(t[root].r);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", &pre[i]);
	for(int i = 0; i < n; ++i) scanf("%d", &post[i]);
	int root = build(0, n-1, 0, n-1);
	if (flag)
		printf("Yes\n");
	else
		printf("No\n");
	inorder(root);
	printf("\n");
	return 0;
}
