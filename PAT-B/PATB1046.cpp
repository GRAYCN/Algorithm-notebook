#include <stdio.h>

int N;
int main(){
	scanf("%d",&N);
	int a1,a2,b1,b2;
	int sumA=0;
	int sumB=0;
	for(int i=1;i<=N;i++){
		scanf("%d%d%d%d",&a1,&a2,&b1,&b2);
		int sum=a1+b1;
		if( (sum==a2 && sum==b2) || (sum !=a2 && sum!=b2) )
			continue;
		if(sum==a2)
			sumB++;
		else if(sum==b2)
			sumA++;
	}
	
	printf("%d %d",sumA,sumB);
	return 0;
}
