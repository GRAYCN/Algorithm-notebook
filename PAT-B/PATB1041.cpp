//PATB1041
#include <stdio.h>
#define maxn 1001

struct stu{
	long long id;
	int examNo;
}testNo[maxn];
int N,M;
int main(){
	scanf("%d",&N);		//�������� 
	long long id;
	int testno,examno;
	for(int i=0;i<N;i++){
		scanf("%lld%d%d",&id,&testno,&examno);
		testNo[testno].id=id;
		testNo[testno].examNo=examno;
	}
	scanf("%d",&M);		//��ѯ����
	int query;
	for(int i=0;i<M;i++){
		scanf("%d",&query);
		printf("%lld %d\n",testNo[query].id,testNo[query].examNo);
	}	 
	return 0;
} 
