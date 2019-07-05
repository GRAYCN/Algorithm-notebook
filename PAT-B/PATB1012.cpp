#include <stdio.h>
#define MAXSIZE 1010
int a[MAXSIZE];
int a1,a2,a3,a5;
double a4;
int N;
int countA1=0,countA2=0,countA3=0,countA4=0,countA5=0,sumA4=0,maxA5=0;
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<N;i++){
		if(a[i]%10==0){
			countA1++;
			a1+=a[i];
		}
		else if(a[i]%5==1){
			countA2++;
			if(countA2%2==1){
				a2+=a[i];
			}else
				a2-=a[i];
		}else if(a[i]%5==2){
			countA3++;
			a3++;
		}else if(a[i]%5==3){
			sumA4+=a[i];
			countA4++;
		}else if(a[i]%5==4){
			countA5++;
			if(a[i]>maxA5)
				maxA5=a[i];
		}
	}
	a4=1.0*sumA4/countA4;
	a5=maxA5;
	if(countA1==0)
		printf("N ");
	else
		printf("%d ",a1);
	if(countA2==0)
		printf("N ");
	else
		printf("%d ",a2);
	if(countA3==0)
		printf("N ");
	else
		printf("%d ",a3);
	if(countA4==0)
		printf("N ");
	else
		printf("%.1f ",a4);
	if(countA5==0)
		printf("N");
	else
		printf("%d",a5);	
}
