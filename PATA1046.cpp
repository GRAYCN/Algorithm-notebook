//PATA1046
/*
	Idea:
	1.�������a,b������������ʹ��a<=b
	2.����c=exit[a]��exit[b-1]�ľ��� d=�ܾ���-c
	3.���c��d�н�С����һ�� 
*/
#include <stdio.h>
#define MAXSIZE 100010
int exit[MAXSIZE]={0};
int N,M,sum=0; 
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d",&exit[i]);
		sum+=exit[i];
	}
	scanf("%d",&M);
	for(int i=1;i<=M;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		if(a>b){		//ʹ��a������b 
			int temp=a;
			a=b;
			b=temp;
		}
		int c=0,d=0;
		for(int i=a;i<b;i++){
			c+=exit[i];
		}
		d=sum-c;
		if(c>=d){
			printf("%d\n",d);
		} else printf("%d\n",c);
	}
	return 0;
} 
