//PATA1046
/*
	Idea:
	1.∂‘ ‰»Îµƒa,bΩ¯––÷ÿ–¬≈≈–Ú£¨ πµ√a<=b
	2.º∆À„c=exit[a]µΩexit[b-1]µƒæ‡¿Î d=◊‹æ‡¿Î-c
	3. ‰≥ˆc∫Õd÷–Ωœ–°µƒƒ«“ª∏ˆ 
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
		if(a>b){		// πµ√a≤ª¥Û”⁄b 
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
