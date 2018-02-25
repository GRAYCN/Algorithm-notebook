//未完待续，第三个测试点无法通过 
// 已经解决，错误原因是在输出前没有化简，这样如果只输入一个分数的时候没有
// 就没有执行化简操作。 
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
struct Fraction {
	long long up,down;
} a, b;

Fraction add(Fraction a,Fraction b) {
	Fraction result;
	result.up = a.up*b.down+a.down*b.up;
	result.down = a.down*b.down;
	return result;
}

long long gcd(long long a,long long b){
	if(b==0){
		return a;
	}else return gcd(b,a%b);

}

Fraction reduction(Fraction a) {
	if(a.down<0) {
		a.down=-a.down;
		a.up=-a.up;
	}
	if(a.up ==0) {
		a.down=1;
	}else{
		int d = gcd(abs(a.up),abs(a.down));
		a.up/=d;
		a.down/=d;
	}
	return a;
}

void showResult(Fraction r){
	r=reduction(r);
	if(r.down==1) printf("%lld",r.up);	
	else if( abs( r.up)>r.down ) 
		printf("%lld %lld/%lld",r.up/r.down, abs(r.up)%r.down,r.down);
	else{
		printf("%lld/%lld",r.up,r.down);
	}
}

int main() {
	int n;
	cin>>n;
	scanf("%lld/%lld",&a.up,&a.down);
	for(int i=1; i<n; i++) {
		scanf("%lld/%lld",&b.up,&b.down);
		a = add(a,b);
		a = reduction(a);
	}
//	showResult(a);
	a=reduction(a);
	if(a.down==1) printf("%lld\n",a.up);
	else if(abs(a.up)>a.down) 
		printf("%lld %lld/%lld",a.up/a.down,abs(a.up)%a.down,a.down);
	else
		printf("%lld/%lld",a.up,a.down);
}
