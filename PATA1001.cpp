#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int num[10];

int main() {
	int a,b,c;
	cin>>a>>b;
	c=a+b;
	if(c<0) {
		cout<<'-';
		c=-c;
	}
	//	string cstr=convert(c);
	int len = 0;
	do{
		num[len++]=c%10;
		c/=10;
	}while(c);
	for(int k=len-1;k>=0;k--){
		cout<<num[k];
		if(k>0 && k%3==0) cout<<",";
	} 
} 
