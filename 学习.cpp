//http://codeup.cn/problem.php?cid=100000566&pid=4
//��һԪ���η��̵ĸ�
#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
int main()
{
	double a,b,c;
	scanf("%lf %lf %lf",&a,&b,&c);
	double r1,r2;
	double temp=sqrt( pow(b,2.0)-4*a*c );
	r1=( -1*b+temp )/(2*a );
 	r2=( -1*b-temp )/(2*a );
 	printf("%f\n",r1);
 	printf("%f\n",r2);
 }

