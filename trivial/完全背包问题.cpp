//��ȫ��������
#include<iostream>
#include<algorithm>
using namespace std;
int w[100],c[1000],dp[100][1000];		//�ֱ��ʾ��������Ʒ����������ֵ���Լ�����Ϊj�ı�������ǰi����Ʒ��õ�����ֵ
int main() {
	int n,V;
	cin>>n>>V;
	for(int i=1; i<=n; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		cin>>c[i];
	}
	//�߽�
	for(int i=0; i<=n; i++) {
		dp[i][0]=0;
	}

	//״̬ת�Ʒ���
	for(int i=1; i<=n; i++) {
		for(int v=w[i]; v<=V; v++) {
			dp[i][v]=max(dp[i-1][v],dp[i][v-w[i]]+c[i]);
		}
	}
	cout<<dp[n][V]; 
}
