//输出应该都没有问题，但是会显示段错误 
#include <cstdio>
#define base 13
char mp[13]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};
int main() {
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int result[8],num=0;
	do {
		result[num++]=a%base;
		a=a/base;
	} while(a!=0);
	num=2;
	do {
		result[num++]=b%base;
		b=b/base;
	} while(b!=0);
	num=4;
	do {
		result[num++]=c%base;
		c=c/base;
	} while(c!=0);
	printf("#%c%c%c%c%c%c",mp[result[1]],mp[result[0]],mp[result[3]],mp[result[2]],mp[result[5]],mp[result[4]]);
	
	return 0;
}
