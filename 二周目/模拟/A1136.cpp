//A1007
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
using namespace std;
#define maxn 10005

struct Num{
	int len;
	int d[1010];
	Num(){
		len=0;
	} 
}a,b,c;

Num change(string str){
	Num a;
	for(int i=str.length()-1;i>=0;i--){
		a.d[a.len++]=str[i]-'0';
	}
	return a;
}

Num add(Num a, Num b){
	int carry=0;
	Num c;
	for(int i=0;i<a.len|| i<b.len;i++){
		int temp=a.d[i]+b.d[i]+carry;
		c.d[c.len++]=temp%10;
		carry=temp/10;
	}
	if(carry>0){
		c.d[c.len++]=carry;
	}
	return c;
}

bool check(int a[],int len){
	bool flag=true;
	for(int i=0;i<len/2;i++){
		if(a[i]!=a[len-1-i]){
			flag=false;
			break;
		}
	}
	return flag;
}

void print(Num a){
	for(int i=a.len-1;i>=0;i--){
		printf("%d",a.d[i]);
	}
}

int main(){
	string input;
	cin>>input;
	a= change(input);	
	int cnt=0;
	while(cnt<10){
		if(check(a.d,a.len)){
			print(a);
			printf(" is a palindromic number.\n");
			return 0;
		}
		b=a;
		reverse(b.d,b.d+b.len);
		c=add(a,b);
		print(a);
		printf(" + ");
		print(b);
		printf(" = ");
		print(c);
		printf("\n");
		a=c;
		cnt++;
	}
	if(cnt==10){
		printf("Not found in 10 iterations.");
		return 0;
	}
}
