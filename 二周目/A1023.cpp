//A1023 
#include<iostream>
#include<cstring>
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

bign multi(bign a, int b){
	bign c;
	int carry=0;
	for(int i=0;i<a.len;i++){
		int temp=a.d[i]*b+carry;
		c.d[c.len++]=temp%10;
		carry=temp/10;
	}
	while(carry!=0){
		c.d[c.len++]=carry%10;
		carry=carry/10;
	}
	return c;
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
//		carry=carry/10;
	}
	return c;
}

void print(bign a){
	for(int i=a.len-1;i>=0;i--){
		cout<<a.d[i];
	}
}

int cnt[10];

int main(){
	char str[25];
	scanf("%s",str);
	bign a = change(str);	
//	bign b = multi(a,2);
	bign b = add(a,a);
	for(int i=0;i<a.len;i++){
		cnt[a.d[i]]++;
	}
	for(int i=0;i<b.len;i++){
		cnt[b.d[i]]--;
	}
	for(int i=0;i<10;i++){
		if(cnt[i]!=0){
			printf("No\n");
			print(b);
			return 0;
		}
	}
	printf("Yes\n");
	print(b);
	return 0;
}
