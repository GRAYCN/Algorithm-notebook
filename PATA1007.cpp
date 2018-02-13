//PATA1007
#include<iostream>
const int maxn =10005;
using namespace std; 
int a[maxn],dp[maxn],s[maxn];
int K;
int main(){
	cin>>K;
	bool flag=true;			//表示全是负数 
	for(int i=0;i<K;i++){
		cin>>a[i];
		if(a[i]>=0) flag=false;
	}
	if(flag==true){
		printf("0 %d %d\n",a[0],a[K-1]);		//输出0和首尾元素 
		return 0;
	}
	dp[0]=a[0];
	s[0]=0;
	for(int i=1;i<K;i++){
		dp[i]=max(a[i],dp[i-1]+a[i]);
		if(a[i]<=dp[i-1]+a[i]){	//等于要不要加在这里？
		//换一种考虑方式，如果不加的话，那么s[i]=i，mss起始下标就会变大，不符合要求 
			s[i]=s[i-1]; 
		}else{
			s[i]=i;
		}
	}
	//找最大的dp
	int max=-1000000000;
	int start,en;
	for(int i=0;i<K;i++){
		if(dp[i]>max){
			max=dp[i];
			start=a[s[i]];
			en=a[i];
		}
	}
	printf("%d %d %d\n",max,start,en); 
}
