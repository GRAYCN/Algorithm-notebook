//PATA1104
// ���ͨ�������ķ�ʽ 
#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 100005
//sum[i]��ʾ���±�Ϊi֮ǰ������Ԫ��֮�� 
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


