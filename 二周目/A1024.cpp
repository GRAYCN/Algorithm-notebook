//A1024
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct bign{
	int len;
	int d[1000];
	bign(){
		len=0;
		memset(d,0,sizeof(d));
	}
};

bign change(char str[]){
	bign a;
	a.len=strlen(str);
	for(int i=0;i<a.len;i++){
		a.d[i]=str[a.len-1-i]-'0';
	}
	return a;
}

bign add(bign a, bign b){
	bign c;
	int carry=0;
	for(int i=0;i<a.len||i<b.len;i++){
		int temp=a.d[i]+b.d[i]+carry;
		c.d[c.len++]=temp%10;
		carry=temp/10;
	}
	if(carry!=0){
		c.d[c.len++]=carry%10;
	}
	return c;
}

void print(bign a){
	for(int i=a.len-1;i>=0;i--){
		cout<<a.d[i];
	}
}

bool check(bign a){
	for(int i=0;i<=a.len/2;i++){
		if(a.d[i]!=a.d[a.len-1-i]){
			return false;
		}
	}
	return true;
}

bign a, b, c;

int main(){
	char str[1000];
	int k;
	scanf("%s%d",str,&k);
	a = change(str);	
	if(check(a)){
		print(a);
		cout<<endl;
		cout<<0;
		return 0;
	}
	else{
		b=a;
		reverse(b.d,b.d + b.len);
		c = add(a,b);
		int cnt=1;
		while(!check(c) && cnt<k){
			a=c;
			b=a;
			reverse(b.d,b.d + b.len);
			c=add(a,b);
			cnt++;
		}
		print(c);
		cout<<endl;
		cout<<cnt;
	}

	
}
