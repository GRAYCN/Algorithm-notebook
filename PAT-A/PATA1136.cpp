//PATA1136
#include<iostream>
#include<cstdio>
#include<cstring>
#include <string>
#include <algorithm>
using namespace std;
char a[1005],b[1005];
struct bign{
	int len;
	int num[1005];
	bign(){
		len=0;
		memset(num,0,sizeof(num));
	}
}bign1,bign2,bign3;

bign change(string a){
	bign n;
	n.len=a.length();
	for(int i=0;i<n.len;i++){
		n.num[i]=a[n.len-1-i]-'0';
	}
	return n;
}

bign add(bign a,bign b){
	bign c;
	int carry=0;
	for(int i=0;i<a.len || i<b.len;i++){
		int temp=a.num[i]+b.num[i]+carry;
		c.num[c.len++]=temp%10;
		carry=temp/10;
	}
	if(carry != 0){
		c.num[c.len++]=carry;
	}
	return c;
}
string convertToString(int num[],int length){
	string str;
	for(int i=length-1;i>=0;i--){
		str+=num[i]+'0';
	}
	return str;
}


void print(bign a){
	for (int i=a.len-1;i>=0;i--){
			cout<<a.num[i];
		}
}
int main(){
	string s,t;
	cin>>s;
	t=s;
	reverse(t.begin(),t.end());
	bign1=change(s);
	bign2=change(t);
	int cnt=0;
	while(cnt<10){
		s=convertToString(bign1.num,bign1.len);
		t=s;
		reverse(t.begin(),t.end());
		bign1=change(s);
		bign2=change(t);
		if (t==s)
		{
			print(bign1); 
			cout<< " is a palindromic number."<<endl;
			break;
		}else{
			print(bign1);
			cout<< " + " ; 
			print(bign2); 
			cout<< " = " ;
			print(add(bign1,bign2));
			cout<<endl;
			bign1=add(bign1,bign2);
			cnt++;
		}
	}
	if (cnt == 10) cout << "Not found in 10 iterations.";
} 
