
//未完待续 段错误 
// 2018-02-14 解决 
#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

struct bign {
	int d[1000];
	int len;
	bign() {
		memset(d,0,sizeof(d));
		len=0;
	}
};

bign change(char str[]) {
	bign c;
	c.len=strlen(str);
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

int ca[15],ca2[15];

int main() {
//	string str;
	char str[21];
	cin>>str;
	bign a;
	a=change(str);
	bign b=a;
	bign a2=add(a,b);
	for(int i=0; i<a.len; i++) {
		ca[a.d[i]]++;
	}
	for(int i=0; i<a2.len; i++) {
		ca2[a2.d[i]]++;
	}
	//比较ca和ca2数组是否完全相等
	bool flag = true;
	for(int i=0;i<10;i++){
		if(ca[i]!=ca2[i])
			flag  = false;
	} 
	if(flag) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	for(int i=a2.len-1;i>=0;i--){
		cout<<a2.d[i];
	}
}
