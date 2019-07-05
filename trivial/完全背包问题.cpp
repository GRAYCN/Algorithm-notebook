//完全背包问题
#include<iostream>
#include<algorithm>
using namespace std;
int w[100],c[1000],dp[100][1000];		//分别表示背包中物品的重量，价值，以及负重为j的背包放入前i件物品获得的最大价值
int main() {
	int n,V;
	cin>>n>>V;
	for(int i=1; i<=n; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		cin>>c[i];
	}
	//边界
	for(int i=0; i<=n; i++) {
		dp[i][0]=0;
	}

	//状态转移方程
	for(int i=1; i<=n; i++) {
		for(int v=w[i]; v<=V; v++) {
			dp[i][v]=max(dp[i-1][v],dp[i][v-w[i]]+c[i]);
		}
	}
	cout<<dp[n][V]; 
}
