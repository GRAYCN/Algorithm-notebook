//PATA1065
#include <stdio.h>
long long int a,b,c;
int N;
long long int sum=0;
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%lld%lld%lld",&a,&b,&c);
		sum=a+b;
		if(a>0 && b>0 && sum<=0)
			printf("Case #%d: true\n",i);
		else if(a<0 && b<0 && sum>=0)
			printf("Case #%d: false\n",i);
		else if(sum>c){
			printf("Case #%d: true\n",i);
		}
		else{
			printf("Case #%d: false\n",i);	
		}
	}
	return 0;
}
