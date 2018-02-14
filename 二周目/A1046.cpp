//A1046
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
using namespace std;
#define maxn 100005

int total;
int sum[maxn];
int a[maxn];

int main(){
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d",&a[i]);
		total+=a[i];
		sum[i]=sum[i-1]+a[i];
	}
	int M;
	scanf("%d",&M);
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		if(a>b){
			swap(a,b);
		}
		int dis=sum[b-1]-sum[a-1];
		int result = min(dis,total-dis);
		printf("%d\n",result);
	}
}
