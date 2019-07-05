//18
//PATA1105
#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
#define maxn 10010
int a[maxn];
int ans[maxn][maxn];
int N;
int m,n;
//���Ĵ���
// ����Ϊm*n
void Print(int m,int n) {
	int num=0;
	int i=1,j=1,k=(n-1)/2;	//������
	int cnt=0;
	int cnt2=0;
	while(cnt<=k) {
		//����
		for(j=1+cnt; j<=n-cnt; j++) {
			if(cnt2<N)
				ans[i][j]=a[num++];
			cnt2++;
		}
		j--;
		//����
		for(i=1+cnt+1; i<=m-cnt-1; i++) {
			if(cnt2<N)
				ans[i][j]=a[num++];
			cnt2++;
		}
		//i--;
		//����
		for(j=n-cnt; j>=1+cnt; j--) {
			if(cnt2<N)
				ans[i][j]=a[num++];
			cnt2++;
		}
		j++;
		//����
		for(i=m-cnt-1; i>=1+cnt+1; i--) {
			if(cnt2<N)
				ans[i][j]=a[num++];
			cnt2++;
		}
		i++;
		cnt++;
	}
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++) {
			printf("%d",ans[i][j]);
			if(j!=n) printf(" ");
		}
		printf("\n");
	}
}


//��mn��ֵ 
void init(){
	for(int i=sqrt((float)N);i>=1;i--){
		if(N%i==0){
			n=i;
			m=N/i;
			return;
		}
	}
}

int cmp(int a,int b){
	return a>b;
}

int main() {
	cin>>N;
	init();
	for(int i=0; i<N; i++) {
		cin>>a[i];
	}
	sort(a,a+N,cmp);
	Print(m,n);
}
