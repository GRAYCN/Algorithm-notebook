#include <cstdio>
#define maxn 40
int result[maxn];
int main(){
	int N,b;
	bool isP =true;
	scanf("%d%d",&N,&b);
	int num=0;
	do{
		result[num++]=N%b;
		N=N/b;
	}while(N!=0);
	for(int i=0;i<num/2;i++){
		if(result[i]!=result[num-1-i]){
			isP=false;
			break;
		}
	}
	if(isP) printf("Yes\n");
	else printf("No\n");
//	for(int i=0;i<num;i++){
	for(int i=num-1;i>=0;i--){
		printf("%d",result[i]);
		if(i!=0) printf(" ");
	}
} 
