//PATB1036

#include <cstdio>

int main() {
	int weight,height;
	char c,space;
	scanf("%d %c",&weight,&c);
	//����������ż����height��ֵ
	if(weight%2==0) height=weight/2;
	else height = weight/2+1;
	//�����һ��
	for(int i=0; i<weight; i++)
		printf("%c",c);
	printf("\n");
	//�����2~height-1��
	for(int i=1; i<height-1; i++) {
		for(int j=0; j<weight; j++) {
			if(j==0 || j==weight-1) printf("%c",c);
			else printf(" ");
		}
		printf("\n");
	}

	//�������һ��
	for(int i=0; i<weight; i++)
		printf("%c",c);
	return 0;
}
