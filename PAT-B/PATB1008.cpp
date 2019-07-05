#include <stdio.h>
#define MAXSIZE 110
int a[MAXSIZE];

int N,M;
int main(){
	scanf("%d%d",&N,&M);
	//对M进行处理
	M=M%N;
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	int count=0;
	for(int i=N-M;i<N;i++)
	{
		printf("%d ",a[i]);
		count++;
	}
	for(int i=0;i<N-M;i++)
	{
		if(count==N-1){
			printf("%d",a[i]);
			break;
		}
		printf("%d ",a[i]);
		count++;
	}
} 
