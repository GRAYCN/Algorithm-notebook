//A1011
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
using namespace std;
double a[1005],b[1005],c[2010];

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
		for(int j=0;j<=1000;j++){
			if(a[i]!=0 && b[j]!=0){
				c[i+j]+=a[i]*b[j];
			}
		}
	}
	for(int i=0;i<=2000;i++){
		if(c[i]!=0) cnt++;
	}
	
	
	cout<<cnt;
	for(int i=2000;i>=0;i--){
		if(c[i]!=0){
			printf(" %d %.1f",i,c[i]);
		}
	}
	
}
