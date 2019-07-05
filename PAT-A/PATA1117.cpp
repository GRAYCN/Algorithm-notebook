//PATA1117
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 100005
int a[maxn];
int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+N);
//	for(int i=N-2;i>=0;i--){
//		if(a[i]<=N-1-i && a[i]!=a[i+1]){
//			cout<<a[i];
//			return 0;
//		}
//	}
	int max=0;
	for(int i=N-1;i>=0;i--){
		if(a[i]>max+1){
			max++;
		}
	}
	cout<<max;
	
}
