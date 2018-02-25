//A1081
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

struct Fraction{
	long long up,down;
}sum, temp;

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

void showResult(Fraction r){
	r=reduction(r);
	if(r.down==1) printf("%lld",r.up);	
	else if( abs( r.up)>r.down ) 
		printf("%lld %lld/%lld",r.up/r.down, abs(r.up)%r.down,r.down);
	else{
		printf("%lld/%lld",r.up,r.down);
	}
}

int main(){
	int N;
	cin>>N;
	sum.up=0;
	sum.down=1;
	for(int i=0;i<N;i++){
		scanf("%lld/%lld",&temp.up,&temp.down);
		sum=add(sum,temp);
	}
	showResult(sum);
}

