//PATB1041
#include <stdio.h>
#define maxn 1001

struct stu{
	long long id;
	int examNo;
}testNo[maxn];
int N,M;
int main(){
	scanf("%d",&N);		//考生人数 
	long long id;
	int testno,examno;
	for(int i=0;i<N;i++){
		scanf("%lld%d%d",&id,&testno,&examno);
		testNo[testno].id=id;
		testNo[testno].examNo=examno;
	}
	scanf("%d",&M);		//查询次数
	int query;
	for(int i=0;i<M;i++){
		scanf("%d",&query);
		printf("%lld %d\n",testNo[query].id,testNo[query].examNo);
	}	 
	return 0;
} 
