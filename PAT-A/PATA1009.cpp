//PATA1009
//���⿼�����ʽ�ĳ˻�����ǰ�����ʽ�Ӽ���ʵ��࣬�������ڣ���Ϊͨ������
//���±�����ʾ����ʽĳһ���ָ�������ﾭ���˻������ΧӦ�ñ��[0,2000]

#include <stdio.h>
#define MAX 1005
double a[MAX],b[MAX],r[2*MAX];
int K;

int main() {
	scanf("%d",&K);
	int e;
	double c;
//	��������
	for(int i=0; i<K; i++) {
		scanf("%d%lf",&e,&c);
		a[e]=c;
	}
	scanf("%d",&K);
	for(int i=0; i<K; i++) {
		scanf("%d%lf",&e,&c);
		b[e]=c;
	}

//����C�е�ϵ���������


//	���г˷�����,��a,b�е��κ�һ����ϵ��ָ����ȫΪ��ʱ���˷����Խ���
	int count =0;
	for(int i=0; i<MAX; i++) {
		for(int j=0; j<MAX; j++) {
			if( (a[i]!=0) || (b[j]!=0) ) {
				double temp = a[i]*b[j];
				if(temp!=0) {
					r[(i+j)]+=temp;
				}
			}
		}
	}

//��c�Ľ���������,����ָ���Ӹߵ��ף���ϵ����Ϊ0ʱ�����
	for(int i=2*MAX-1; i>=0; i--) {
		if(r[i]!=0)
			count++;
	}
//����Ҫ������ֵ
	if(count == 0) {
		printf("1 0 0");
	} else {
		printf("%d",count);
		for(int i=2*MAX-1; i>=0; i--) {
			if(r[i]!=0) {
				printf(" %d %.1f",i,r[i]);
			}
		}
	}

	return 0;
}
