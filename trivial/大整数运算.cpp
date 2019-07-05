#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct bign {
	int d[1000];
	int len;
	bign() {
		memset(d,0,sizeof(d));
		len=0;
	}
};

bign change(string str) {
	bign a;
	a.len = str.length();
	for(int i=0; i<a.len; i++) {
		a.d[i]=str[a.len-i-1]-'0';
	}
	return a;
}

int compare(big a,big b) {
	if(a.len>b.len) return 1;		//a大
	else if(a.len<b.len) return -1;
	else {
		for(int i=a.len-1; i>=0; i--) {		//从高位往低位进行比较
			if(a.d[i]>b.d[i]) return 1;
			esle if(a,d[i]<b.d[i]) return -1;
		}
		return 0;			//两数相等
	}
}

//高精度加法
bign add(bign a, bign b) {
	bign c;
	int carry = 0;
	for(int i=0; i<a.len || i<b.len; i++) {
		int temp = a.d[i]+b.d[i]+carry;
		c.d[c.len++]=temp%10;		//个位数为该位结果
		carry = temp/10;			//十位数为新的进位
	}
	if(carry != 0) {		//如果最后进位不为0，则直接赋值给结果的最高位
		c.d[c.len++] = carry;
	}
}

//高精度减法
bign sub(bign a, bign b) {
	bign c;
	for(int i=0; i<a.len || i<b.len; i++) {
		if(a.d[i]<b.d[i]) {	//如果不够减，要向高位借位
			a.d[i+1]--;
			a.d[i]+=10;		
		}
		c.d[c.len++] = a.d[i]-b.d[i]; 
	}
	while(c.len - 1 >= 1 && c.d[c.len-1] == 0){
		c.len--;		//去掉高位的0，同时至少保留一位最低位 
	}
	return c;
}

bign multi(bign a, int b){		//高精度乘法 
	bign c;
	int carry = 0;
	for(int i=0;i<a.len;i++){
		int temp = a.d[i]*b+carry;
		c.d[c.len++]=temp%10;
		carry = temp/10;
	}
	while(carry != 0){			//和加法不一样，乘法的进位可能不止一位，因此这里使用while 
		c.d[c.len++] = carry%10;
		carry/=10;
	}
	return c;
}

//高精度除法运算 
bign divide(bign a, int b, int& r){
	bign c;
	c.len=a.len;		//被除数的每一位和商的每一位是一一对应的，因此先令长度相等
	for(int i=a.len-1;i>=0;i--){	//从高位开始 
		r = r*10+a.d[i];		//和上一位遗留的余数组合 ？？
		if(r<b) c.d[i]=0;
		else{
			c.d[i]=r/b;
			r=r%b;	
		} 
	} 
	while(c.len-1 >=1 && c.d[c.len-1] ==0){
		c.len--;		//去除高位的0，同时至少保留一位最低位 
	}
	return c; 
}

int main() {

}
