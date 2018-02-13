//PATA1078
/*
˼·�������ϣ��Ĵ�СM���������ֵ���ĿN���;��������
��M����һ������ʱ���ҵ�����M����С��������ֵ��M
*/
#include<iostream>
#include<math.h>
#define maxn 10005
using namespace std;
int filled[maxn];
int position[maxn];
bool isPrime(int n) {
	if(n<=1) return false;
	int sqr=(int)sqrt(n*1.0);
	for(int i=2; i<=sqr; i++) {
		if(n%i==0)
			return false;
	}
	return true;
}

int main() {
	int M,N;
	cin>>M>>N;
	while(!isPrime(M)) {
		M++;
	}
	int in;
	for(int i =0; i<N; i++) {
//		cin>>a[i];
		cin>>in;
		int pos = in%M;
		int j=1;
		while(pos<M) {
			if(filled[pos]) {
				j++;
				pos+=j*j;
			}
		}
		if(pos<M){
			position[i]=pos;
		} 
		else position[i]=-1;
	}
	
	//���
	for(int i=0;i<N;i++){
		if(i!=0) printf(" ");
		if(position[i]==-1) printf("-");
		else cout<<position[i];
	} 
}

