//PATA1024
#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

struct bign {
	int d[21];
	int len;
	bign() {
		memset(d,0,sizeof(d));
		len=0;
	}
};

bign change(string str) {
	bign c;
	c.len=str.length();
	//	int num=0;
	for(int i=0; i<c.len; i++) {
		c.d[i]=str[c.len-i-1]-'0';
	}
	return c;
}

bign add(bign a,bign b) {
	bign c;
	int carry = 0;
	for(int i=0; i<a.len || i<b.len; i++) {
		int temp = a.d[i]+b.d[i]+carry;
		c.d[c.len++]=temp%10;
		carry = temp/10;
	}
	if(carry !=0) {
		c.d[c.len++] = carry;
	}
	return c;
}

bool Judge(bign a) {
	for(int i=0; i<=a.len/2; i++) {
		if(a.d[i]!=a.d[a.len-1-i])
			return false;
	}
	return true;
}

void print(bign a){
	for(int i=a.len-1;i>=0;i--){
		cout<<a.d[i];
	}
	cout<<endl;
}

int main(){
	string str;
	int T,k=0;
	cin>>str>>T;
	bign a = change(str);
	while(k<T && Judge(a) == false){
		bign b=a;
		reverse(b.d,b.d+b.len);
		a=add(a,b);
		k++;
	}
	print(a);
	cout<<k<<endl;
}
