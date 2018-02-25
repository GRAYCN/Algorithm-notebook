//PATA1040
// It's a little hard to understand. 
#include<iostream>
#include<string>
using namespace std;
const int maxn = 1010;
//char S[maxn];
string S;
int dp[maxn][maxn];

int main(){
	cin>>S;
	int len=S.length(),ans=1;
	fill(dp[0],dp[0]+maxn*maxn,0);
	//边界：
	for(int i=0;i<len;i++){
		dp[i][i]=1;
		if(i<len-1){
			if(S[i]==S[i+1]){
				dp[i][i+1]=1;
				ans=2;
			}
		}
	}
	
	//状态转移方程
	for(int L=3;L<=len;L++){
		for(int i=0;i+L-1<len;i++){
			int j=i+L-1;
			if(S[i]==S[j] && dp[i+1][j-1]==1){
				dp[i][j]=1;
				ans=L;
			}
		}
	}
	cout<<ans; 
}
