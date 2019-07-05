//PATB1027

#include <cstdio>

int main() {
	int n;
	char c;
	scanf("%d %c",&n,&c);
	int total=1;
	int length,count;
	for(int i=2;; i++) {
		total+=2*(2*i-1);
		if(total>n) {
			length=2*i-3;		//length存储第一行的符号数目，count存储一个倒三角的高度
			count=i-1;
			total-=2*(2*i-1);	//实际使用的符号数目
			break;

		}
	}
	//输出倒三角
	for(int i=0; i<count; i++) {
		for(int j=0; j<i; j++) {
			printf(" ");
		}
		for(int j=0; j<length; j++) {
			printf("%c",c);
		}
		length-=2;
		printf("\n");		//换行
	}
	length+=2;
	//输出上三角
	for(int i=count-2; i>=0; i--) {
		for(int j=0; j<i; j++) {
			printf(" ");
		}
		length+=2;
		for(int j=0; j<length; j++) {
			printf("%c",c);
		}
		printf("\n");		//换行
	}
	printf("%d",n-total);
	return 0;
}
