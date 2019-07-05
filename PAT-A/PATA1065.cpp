//PATA1065
#include <stdio.h>
long long int a,b,c;
int N;
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%lld%lld%lld",&a,&b,&c);
		if(a+b>c){
			printf("Case #%d: true\n",i);
		}
		else{
			printf("Case #%d: false\n",i);	
		}
	}
	return 0;
}
