//PATB1010
/*
	˼·��
	1.��a[MAX][2]��ʾÿһ�����a[MAX][0]��ϵ����a[MAX][1]��ָ��
	2.a[MAX][0]*=a[MAX][1], a[MAX][1]--
	3.�������ʱ�����˵a[MAX][0]=0,�������ϵ����ָ��
*/

#include <stdio.h>
#define MAX 1005
int a[MAX][2]= {0};
int main() {
	int k,e;
	int i=0,count=0;
	while(scanf("%d%d",&k,&e) != EOF) {
		a[i][0]=k;
		a[i][1]=e;
		if(e!=0) {
			a[i][0]*=a[i][1];
			a[i][1]--;
			count++;
		} else {
			a[i][0]=0;
		}
		i++;

	}

	//����
	if(count == 0) {
		printf("0 0");
	}
	for(int i=0; i<count; i++) {
		if(a[i][0]!=0) {
			if (i!=0) printf(" ");
			printf("%d %d",a[i][0],a[i][1]);
		}
	}
	return 0;
}
