//PATA1104
// 如果通过这样的方式 
#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 100005
//sum[i]表示在下标为i之前的所有元素之和 
double sum[maxn];
int N;
int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>sum[i+1];
		sum[i+1]+=sum[i];
	}
	double all=0;
	for(int i=0;i<=N;i++){
		for(int j=i+1;j<=N;j++){
			all+=sum[j]-sum[i];
		}
	}
	printf("%.2f",all);
}


