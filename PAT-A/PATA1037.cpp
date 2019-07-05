//PATA1037
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 100005
int a[maxn],b[maxn];
int NC,NP;
int main(){
	scanf("%d",&NC);
	for(int i=0;i<NC;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&NP);
	for(int i=0;i<NP;i++){
		scanf("%d",&b[i]);
	}
	sort(a,a+NC);
	sort(b,b+NP);
	int i,j;
	int sum=0;
	for(i=0,j=0;a[i]<0&&b[j]<0;i++,j++){
		sum+=a[i]*b[j];
	}
	for(i=NC-1,j=NP-1;a[i]>0&&b[j]>0;i--,j--){
		sum+=a[i]*b[j];
	}
	cout<<sum;
}
