//0-1背包问题
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100;		//物件最大数目
const int maxv=1000;	//V的上限
int w[maxn],c[maxn],dp[maxn][maxv]; 
int main(){
	int n,V;
	cin>>n>>V;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}	
	//边界
	for(int i=0;i<=n;i++){
		dp[i][0]=0;
	} 

	//状态转移方程
	for(int i=1;i<=n;i++){
		for(int v=w[i];v<=V;v++){
			dp[i][v]=max(dp[i-1][v],dp[i-1][v-w[i]]+c[i]);
		}
	} 

	cout<<dp[n][V];

} 
