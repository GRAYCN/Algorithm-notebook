//PATA1088
#include<iostream>
#include<algorithm>
#include<math.h>
typedef long long ll;
using namespace std;
struct Fraction {
	ll up,down;
} a, b;

ll gcd(ll a,ll b) {
	if(b==0) return a;
	return gcd(b,a%b);
}

Fraction reduc(Fraction a) {
	if(a.down<0) {
		a.up=-a.up;
		a.down=-a.down;
	}
	if(a.up==0) {
		a.down=1;
	} else {
		ll d=abs(gcd(a.up,a.down));
		a.up/=d;
		a.down/=d;
	}
	return a;
}

//输出分数a
void print(Fraction a) {
	//先对a进行化简
	a=reduc(a);
	int flag=1;
	if(a.up<0) {
		cout<<"(";
		flag=0;
	}
	if(a.down==1) {
		cout<<a.up;
	} else if(abs(a.up)>a.down) {
		ll temp=a.up/a.down;
		a.up=abs(a.up)%a.down;
		printf("%lld %lld/%lld",temp,a.up,a.down);
	}else{
		printf("%lld/%lld",a.up,a.down);
	}

	if(flag==0) {
		cout<<")";
	}
}

//求和
void add(Fraction a,Fraction b) {
	Fraction c;
	c.up=a.down*b.up+a.up*b.down;
	c.down=a.down*b.down;
	c=reduc(c);
	print(a);
	printf(" + ");
	print(b);
	printf(" = ");
	print(c);
	printf("\n");
}
//求差
void diff(Fraction a,Fraction b) {
	Fraction c;
	c.up=a.up*b.down-a.down*b.up;
	c.down=a.down*b.down;
	c=reduc(c);
	print(a);
	printf(" - ");
	print(b);
	printf(" = ");
	print(c);
		printf("\n");
}

//求积
void product(Fraction a,Fraction b) {
	Fraction c;
	c.up=a.up*b.up;
	c.down=a.down*b.down;
	c=reduc(c);
	print(a);
	printf(" * ");
	print(b);
	printf(" = ");
	print(c);
		printf("\n");
}

//求商
void quotient(Fraction a,Fraction b) {
	if(b.up!=0) {
		Fraction c;
		c.up=a.up*b.down;
		c.down=a.down*b.up;
		c=reduc(c);
		print(a);
		printf(" / ");
		print(b);
		printf(" = ");
		print(c);
			printf("\n");
	} else {
		//输出INF
		print(a);
		printf(" / ");
		print(b);
		printf(" = Inf");
		printf("\n");
	}

}

int main() {
	scanf("%lld/%lld %lld/%lld",&a.up,&a.down,&b.up,&b.down);
	add(a,b);
	diff(a,b);
	product(a,b);
	quotient(a,b);
}
