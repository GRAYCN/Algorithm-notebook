//0-1��������
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100;		//��������Ŀ
const int maxv=1000;	//V������
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
	//�߽�
	for(int i=0;i<=n;i++){
		dp[i][0]=0;
	} 

	//״̬ת�Ʒ���
	for(int i=1;i<=n;i++){
		for(int v=w[i];v<=V;v++){
			dp[i][v]=max(dp[i-1][v],dp[i-1][v-w[i]]+c[i]);
		}
	} 

	cout<<dp[n][V];

} 
