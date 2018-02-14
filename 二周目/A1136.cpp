//A1136
//这里使用晴神宝典中的模板需要注意将bign中的d的数组大小设置为10000，不然容易越界，另外最好获取输入使用string
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
using namespace std;
struct bign{
	int len;
	int d[10000];
	bign(){
		len=0;
		memset(d,0,sizeof(d));
	}
};

bign change(string str){
	bign a;
	a.len=str.length();
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
//char str[1000];
string str;
int main(){

	cin>>str;
	a = change(str);	
	if(check(a)){
		print(a);
		printf(" is a palindromic number."); 
		return 0;
	}
	else{
		b=a;
		reverse(b.d,b.d + b.len);
		c = add(a,b);
		print(a);
		cout<<" + ";
		print(b);
		cout<<" = ";
		print(c);
		cout<<endl;
		if(check(c)){
			print(c);
			printf(" is a palindromic number."); 
			return 0;
		}
		int cnt=1;
		while(!check(c) && cnt<10){
			a=c;
			b=a;
			reverse(b.d,b.d + b.len);
			c=add(a,b);
			print(a);
			cout<<" + ";
			print(b);
			cout<<" = ";
			print(c);
			cout<<endl;
			cnt++;
		}
		if(cnt<10){
			print(c);
			printf(" is a palindromic number."); 
		}else{
			printf("Not found in 10 iterations.");
		}
	}
}
