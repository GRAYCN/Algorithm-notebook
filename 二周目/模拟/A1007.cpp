//A1007
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
using namespace std;
#define maxn 10005
int a[maxn];
int dp[maxn];
int start[maxn];
int main(){
	int K;
	cin>>K;
	bool flag=false;
	for(int i=0;i<K;i++){
		cin>>a[i];
		if(a[i]>=0){
			flag=true;
		}
	}
	if(flag==false){
		printf("0 %d %d",a[0],a[K-1]);
		return 0;
	}else{
		dp[0]=a[0];
		for(int i=1;i<K;i++){
			if(dp[i-1]>=0){
				dp[i]=dp[i-1]+a[i];
				start[i]=start[i-1];
			}else{
				dp[i]=a[i];
				start[i]=i;
			}
		}
		int max=0;
		for(int i=0;i<K;i++){
			if(dp[i]>dp[max]){
				max=i;
			}
		}
//		printf("%d %d %d",dp[max],start[max],max);
		printf("%d %d %d",dp[max],a[start[max]],a[max]);
	}
} 
