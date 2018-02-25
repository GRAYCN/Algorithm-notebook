//A1088
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

struct Fraction{
	long long up,down;
}a,b;

long long gcd(long long a,long long b){
	if(b==0) return a;
	else return gcd(b,a%b);
}

Fraction reduction(Fraction result){
	if(result.down<0){
		result.up=-result.up;
		result.down=-result.down;
	}
	if(result.up==0){
		result.down=1;
	}else{
		long long d = gcd(abs(result.up),abs(result.down));
		result.up /= d;
		result.down /= d;
	}
	return result;
}

Fraction add(Fraction f1, Fraction f2){
	Fraction result;
	result.up=f1.up*f2.down+f1.down*f2.up;
	result.down=f1.down*f2.down;
	return reduction(result);
}

Fraction sub(Fraction f1, Fraction f2){
	Fraction result;
	result.up=f1.up*f2.down-f1.down*f2.up;
	result.down=f1.down*f2.down;
	return reduction(result);
}

Fraction multi(Fraction f1, Fraction f2){
	Fraction result;
	result.up=f1.up*f2.up;
	result.down=f1.down*f2.down;
	return reduction(result);
}

Fraction division(Fraction f1, Fraction f2){
	Fraction result;
	result.up=f1.up*f2.down;
	result.down=f1.down*f2.up;
	return reduction(result);
}

void showResult(Fraction r){
	r=reduction(r);
	if(r.up<0) printf("(");
	if(r.down==1) printf("%lld",r.up);	
	else if( abs( r.up)>r.down ) 
		printf("%lld %lld/%lld",r.up/r.down, abs(r.up)%r.down,r.down);
	else{
		printf("%lld/%lld",r.up,r.down);
	}
	if(r.up<0) printf(")");
}

int main(){
	scanf("%lld/%lld %lld/%lld",&a.up,&a.down,&b.up,&b.down);
	reduction(a);
	reduction(b);
	Fraction result;
	result=add(a,b);
	showResult(a);
	printf(" + ");
	showResult(b);
	printf(" = ");
	showResult(result);
	printf("\n");
	
	result=sub(a,b);
	showResult(a);
	printf(" - ");
	showResult(b);
	printf(" = ");
	showResult(result);
	printf("\n");
	
	result=multi(a,b);
	showResult(a);
	printf(" * ");
	showResult(b);
	printf(" = ");
	showResult(result);
	printf("\n");
	
	if(b.up!=0)
		result=division(a,b);
	showResult(a);
	printf(" / ");
	showResult(b);
	printf(" = ");
	if(b.up!=0)
		showResult(result);
	else printf("Inf");
	printf("\n");
}

