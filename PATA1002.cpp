//PATA1002
//just for test
//just for test
#include <stdio.h>
#define MAXSIZE 1005
double a[MAXSIZE],b[MAXSIZE],c[MAXSIZE];

int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int e;
		double c;
		scanf("%d%lf",&e,&c);
		a[e]=c;
	}
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int e;
		double c;
		scanf("%d%lf",&e,&c);
		b[e]=c;
	}
	int count=0;
	for(int i=0;i<=1000;i++)
	{
		c[i]=a[i]+b[i];
		if(c[i]!=0) count++;
	}
	printf("%d",count);
	for(int i=1000;i>=0;i--){
		if(c[i]!=0){
			printf(" %d %.1f",i,c[i]);
		}
	}
	return 0;
} 
