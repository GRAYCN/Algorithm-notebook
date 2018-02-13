//PATA1029
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define maxn 1000005
int a[maxn],b[maxn],c[2*maxn];
int main() {
	int N;
	cin>>N;
	for(int i=0; i<N; i++) {
		cin>>a[i];
	}
	int M;
	cin>>M;
	for(int i=0; i<M; i++) {
		cin>>b[i];
	}
	//在c中的中位数下标是（N+M-1)/2
	//合并a和b
	int i=0,j=0,index=0;
	while(i<N && j<M){
		if(a[i]<=b[j]){
			c[index++]=a[i++];
		}else{
			c[index++]=b[j++];
		}
	}
	while(i<N) c[index++]=a[i++];
	while(j<M) c[index++]=b[j++];
	cout<<c[(N+M-1)/2]; 
}
