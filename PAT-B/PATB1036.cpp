//PATB1036

#include <cstdio>

int main() {
	int weight,height;
	char c,space;
	scanf("%d %c",&weight,&c);
	//根据奇数和偶数给height赋值
	if(weight%2==0) height=weight/2;
	else height = weight/2+1;
	//处理第一行
	for(int i=0; i<weight; i++)
		printf("%c",c);
	printf("\n");
	//处理第2~height-1行
	for(int i=1; i<height-1; i++) {
		for(int j=0; j<weight; j++) {
			if(j==0 || j==weight-1) printf("%c",c);
			else printf(" ");
		}
		printf("\n");
	}

	//处理最后一行
	for(int i=0; i<weight; i++)
		printf("%c",c);
	return 0;
}
