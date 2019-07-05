//PATA1113
#include<iostream>
using namespace std;
#include <algorithm>
#define maxn 100005
int N;
int a[maxn];
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
	} 
	sort(a,a+N);
	int middle=N/2;
	int maxN=N%2==0? 0:1;
	int maxS;
	int sumBefore=0,sumAfter=0;
	for(int i=0;i<middle;i++){
		sumBefore+=a[i];
	}
	for(int i=middle;i<N;i++){
		sumAfter+=a[i];
	}
	maxS=sumAfter-sumBefore;
	printf("%d %d",maxN,maxS);
}
