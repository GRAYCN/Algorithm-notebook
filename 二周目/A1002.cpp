//A1002
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
using namespace std;
double a[1005],b[1005],c[1005];

int main(){
	int K;
	cin>>K;
	int exp;
	double cof;
	for(int i=0;i<K;i++){
		cin>>exp>>cof;
		a[exp]=cof;
	}
	cin>>K;
	for(int i=0;i<K;i++){
		cin>>exp>>cof;
		b[exp]=cof;
	}
	int cnt=0;
	for(int i=0;i<=1000;i++){
		c[i]=a[i]+b[i];
		if(c[i]!=0){
			cnt++;
		}
	}
	cout<<cnt;
	for(int i=1000;i>=0;i--){
		if(c[i]!=0){
			printf(" %d %.1f",i,c[i]);
		}
	}
	
}
