#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 100005
int N,M;
int a[maxn];
int sum[maxn];
int nearS=(1<<9);

int main(){
	cin>>N>>M;
	for(int i=1;i<=N;i++){
		cin>>sum[i];
		sum[i]+=sum[i-1];		//��¼�±�ΪiΪֹ�ļ�ֵ�ܺ� 
	}
	for(int i=1;i<=N;i++){
		//�鿴�Ƿ�����sum[j]-sum[i-1]==M ��[i,j]���䷶Χ�ڵĺ���S
		//Ҳ����˵��sum���ҵ�����һ���±�j��ʹ��M+sum[i-1]>sum[j]�״γ��� 
		int j=upper_bound(sum+i,sum+N+1,sum[i-1]+M)-sum;
		//����ҵ���[i,j-1]�պ�ʹ�ü�ֵ֮��ΪM
		if(sum[j-1] - sum[i-1] == M){
			nearS=M;			//��ӽ�M�ľ���M; 
			break;
		}
		//�����ҵ�ʹ��  sum[j-1] - sum[i-1] ��ӽ�M������ΪNesrS
		else{
			if(j<=N && (sum[j] - sum[i-1]) < nearS){
				nearS=sum[j] - sum[i-1];		//����ʹ��j������j-1��ԭ����Ҫ�ú���� 
			}
		} 
	}

	for(int i=1;i<=N;i++){
		int j=upper_bound(sum+i,sum+N+1,sum[i-1]+nearS)-sum;
		if(sum[j-1]-sum[i-1]==nearS){

			printf("%d-%d\n",i,j-1);
		}
	}
}
