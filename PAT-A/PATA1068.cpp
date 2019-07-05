//PATA1068
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define maxn 10005
#define maxm 105
int value[maxn],dp[maxn][maxm];
vector<int> v;
int N,M;
int main() {
	scanf("%d%d",&N,&M);
	for(int i=1; i<=N; i++) {
		scanf("%d",&value[i]);
	}
	//设置边界条件
	for(int i=0; i<=M; i++) {
		dp[0][i]=0;
	}

	//对value排序
	sort(value+1,value+N+1);

	//状态转移方程
	bool flag=false;
	int n,m;		//记录结果的i,j；
	for(int i=1; i<=N; i++) {
		for(int j=value[i]; j<=M; j++) {
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-value[i]]+value[i]);
			if(j==M && dp[i][j]==M) {
				flag=true;
				n=i;
				m=j;
				break;
			}
		}
		if(flag==true) break;
	}
	if(flag==false) {
		printf("No Solution\n");
	} else {

		for(int i=n; i>=0; i--) {
			if(dp[i][M]>dp[i-1][M]) {
				v.push_back(i);
			}
		}
		for(int i=v.size()-1;i>=0;i--){
			printf("%d\n",value[v[i]]);
		}
	}
}
