//BigInteger
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

struct bign{
	int d[1000];		//sometimes the size of this array can be larger.
	int len;
	bign(){
		memset(d,0,sizeof(d));
		len=0;
	}
};

bign change(char str[]){		//or string recommend for string
	bign a;
	a.len=strlen(str);
	for(int i=0;i<a.len;i++){
		a.d[i]=str[a.len-i-1]-'0';
	}
	return a;
}

int compare(bign a,bign b){
	if( a.len > b.len ) return 1; //a is bigger
	else if(a.len < b.len ) return -1;
	else{
		for(int i=a.len-1;i >= 0;i--){
			if(a.d[i] > b.d[i]) return 1;
			else if(a.d[i] < b.d[i]) return -1;
		}
		return 0;
	}
}

bign add(bign a, bign b){
	bign c;
	int carry=0;
	for(int i=0; i<a.len||i<b.len; i++){
		int temp= a.d[i]+b.d[i]+carry;
		c.d[c.len++]=temp%10;
		carry=temp/10;
	}
	if( carry>0 ){
		c.d[c.len++]=carry;
	}
	return c;
}

bign sub(bign a,bign b){
	bign c;
	for(int i=0; i<a.len||i<b.len; i++){
		if(a.d[i]<b.d[i]){
			a.d[i+1]--;
			a.d[i]+=10;
		}
		c.d[c.len++]=a.d[i]-b.d[i];
	}
	//delete the redundant 0
	while(c.len-1>=1 && c.d[c.len-1] ==0){
		c.len--;
	}
	return c;
}

bign multi(bign a, int b){
	bign c;
	int carry=0;
	for(int i=0;i<a.len;i++){
		int temp = a.d[i]*b+carry;
		c.d[c.len++]=temp%10;
		carry=temp/10;
	}
	while(carry>0){
		c.d[c.len++]=carry%10;
		carry/=10;
	}
	return c;
}

bign divide(bign a, int b, int& r){
	bign c;
	c.len=a.len;
	for(int i=a.len-1;i>=0;i--){
		r=r*10+a.d[i];
		if(r<b){
			c.d[i]=0;
		}else{
			c.d[i]=r/b;
			r=r%b;
		}
	}
	while(c.len-1>=1 && c.d[c.len-1]==0){
		c.len--;
	}
	return c;
}

void print(bign a){
	for(int i=a.len-1;i>=0;i--){
		printf("%d",a.d[i]);
	}
}

int main(){
	char str1[1000],str2[1000];
	scanf("%s%s",str1,str2);
	bign a = change(str1);
	bign b = change(str2);
	print(add(a,b));
	cout<<endl;
	print(sub(a,b));
	cout<<endl;
	print(multi(a,3));
	cout<<endl;
	int remainder=0;
	print(divide(a,2,remainder));		// or remainder can be global var
	cout<<endl;
	cout<<remainder<<endl;
}


