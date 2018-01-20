//PATA1046
/*
	Idea:
	1.对输入的a,b进行重新排序，使得a<=b
	2.计算c=exit[a]到exit[b-1]的距离 d=总距离-c
	3.输出c和d中较小的那一个 
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
		if(a>b){		//使得a不大于b 
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
