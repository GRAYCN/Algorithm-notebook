//fraction
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

struct Fraction{
	long long up,down;
};

Fraction reduction(Fraction result){
	if(result.down<0){
		result.up=-result.up;
		result.down=-result.down;
	}
	if(result.up==0){
		result.down=1;
	}else{
		int d = gcd(abs(result.up),abs(result.down));
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

// before use divide, you should check whether if f2.down is zero
Fraction divide(Fraction f1, Fraction f2){		
	Fraction result;
	result.up=f1.up*f2.down;
	result.down=f1.down*f2.up;
	return reduction(result);
}

void showResult(Fraction r){
	r=reduction(r);
	if(r.down==1) printf("%lld",r.up);	
	else if( abs( r.up)>r.down ) 
		printf("%lld %lld/%lld",r.up/r.down, abs(r.up)%r.down,r.down);
	}else{
		printf("%lld/%lld",r.up,r.down);
	}
}

int main(){
	
}


