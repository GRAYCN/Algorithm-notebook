#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
#define maxn 10005
int N;
int a[maxn],result[100][100];

int findM(){
	int temp=sqrt((double)N);
	while(N%temp!=0){
		temp++;
	}
	return temp;
}

int cmp(int a, int b){
	return a>b;
}

int main(){
	cin>>N;
	int m,n;
	m=findM();
	n=N/m;
	for(int i=0;i<N;i++){
		cin>>a[i];
	}
	sort(a,a+N,cmp);
	int num=0;
	int j=0;
	while(num<N){
		for(int i=j;i<n-j && num<N;i++){
			result[j][i]=a[num++];
		}
		for(int i=j;i<m-j && num<N;i++){
			result[i][n-1-j]=a[num++];
		}
		for(int i=n-j-1;i>=j && num<N;i--){
			result[m-1-j][i]=a[num++];
		}
		for(int i=m-j-1;i>=j && num<N;i--){
			result[i][j]=a[num++];
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<result[i][j];
			if(j!=n-1) cout<<" ";
		}
		cout<<endl;
	}
	return 0;
} 
