//PATA1009
//本题考查多项式的乘积，与前面多项式加减其实差不多，区别在于：因为通过数组
//的下标来表示多项式某一项的指数，这里经过乘积运算后范围应该变成[0,2000]

#include <stdio.h>
#define MAX 1005
double a[MAX],b[MAX],r[2*MAX];
int K;

int main() {
	scanf("%d",&K);
	int e;
	double c;
//	处理输入
	for(int i=0; i<K; i++) {
		scanf("%d%lf",&e,&c);
		a[e]=c;
	}
	scanf("%d",&K);
	for(int i=0; i<K; i++) {
		scanf("%d%lf",&e,&c);
		b[e]=c;
	}

//计算C中的系数非零个数


//	进行乘法运算,当a,b中的任何一个的系数指数不全为零时，乘法可以进行
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

//将c的结果输出出来,按照指数从高到底，当系数不为0时就输出
	for(int i=2*MAX-1; i>=0; i--) {
		if(r[i]!=0)
			count++;
	}
//首先要处理特值
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
