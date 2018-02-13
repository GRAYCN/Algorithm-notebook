//PATA1125
#include<iostream>
using namespace std;
#include<algorithm>
#define maxn 10005
int a[maxn];

double mypow(double a, int b){
	double result=1;
	while(b--){
		result*=a;
	}
	return result;
}
int N;
int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>a[i];
	}
	sort(a,a+N);
	double ans=0;
	for(int i=0;i<N;i++){
		int left,right;
		left= i==0?0:1;
		right = N-1-i;
		ans+=a[i]*mypow(0.5,left+right);
	}
	int ansInt = ans>a[N-1]? a[N-1]: ans;
	cout<<ansInt;
}
