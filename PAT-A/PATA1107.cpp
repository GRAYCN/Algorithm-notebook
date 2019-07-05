//PATA1107
#include<iostream>
#include<algorithm>
#define maxn 1010
using namespace std;
int father[maxn];
int isRoot[maxn];
int course[maxn];

int findFather(int x) {
	int a=x;
	while(x!=father[x]) {
		x=father[x];
	}
	while(a!=father[a]) {
		int z=a;
		a=father[a];
		father[z]=x;
	}
	return x;
}

void init(int n) {
	for(int i=1; i<=n; i++) {
		father[i]=i;
		isRoot[i]=false;
	}
}

void Union(int a,int b) {
	int faA=findFather(a);
	int faB=findFather(b);
	if(faA!=faB) {
		father[faA]=faB;
	}
}

int cmp(int a,int b) {
	return a>b;
}

int main() {
	int n,k,h;
	cin>>n;
	init(n);
	for(int i=1; i<=n; i++) {
		scanf("%d:",&k);
		for(int j=0; j<k; j++) {
			cin>>h;
			if(course[h]==0) {
				course[h]=i;
			}
			Union(i,findFather(course[h]));
		}
	}
	for(int i=1;i<=n;i++){
		isRoot[findFather(i)]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(isRoot[i]!=0){
			ans++;
		}
	}
	cout<<ans<<endl;
	sort(isRoot,isRoot+n,cmp);
	for(int i=0;i<ans;i++){
		cout<<isRoot[i];
		if(i<ans-1) cout<<" "; 
	}
}
