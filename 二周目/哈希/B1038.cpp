//19'
#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<string>
#include<cctype>
using namespace std;
int a[105];

int main(){
	int N,K;
	cin>>N;
	for(int i=0;i<N;i++){
		int temp;
		cin>>temp;
		a[temp]++;
	}
	cin>>K;
	for(int i=0;i<K;i++){
		int query;
		cin>>query;
		cout<<a[query];
		if(i!=K-1) printf(" ");
	}
}
