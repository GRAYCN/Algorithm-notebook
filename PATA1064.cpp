//PATA1064
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 1010

int n,number[maxn],CBT[maxn],index=0;
void inOrder(int root){
	if(root>n) return;
	inOrder(root*2);
	CBT[root]=number[index++];
	inOrder(root*2+1);
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>number[i];
	}
	sort(number,number+n);
	inOrder(1);
	for(int i=1;i<=n;i++){
		cout<<CBT[i];
		if(i<n) cout<<" "; 
	}
}
