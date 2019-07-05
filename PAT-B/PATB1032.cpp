#include <iostream>
using namespace std;
#include <stdio.h>

#define MAXSIZE 100001

int a[MAXSIZE]={0};
int N;

int main() {	
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		int num,gra;
		scanf("%d%d",&num,&gra);
		a[num]+=gra;
	}
	int maxNum=0;
	int maxGra=0;
	for(int i=1;i<=N;i++){
		if(a[i]>maxGra){
			maxGra=a[i];
			maxNum=i;
		}
	}
	printf("%d %d",maxNum,maxGra);
	return 0;
} 
