//A1132
#include<iostream>
#include<string>
#include<algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

string str;
int N;

void convert(int& a, int& b,int& c){
	int len=str.length();
	for(int i=0;i<len/2;i++){
		a=a*10+str[i]-'0';
		c=c*10+str[i]-'0';
	}
	for(int i=len/2;i<len;i++){
		b=b*10+str[i]-'0';
		c=c*10+str[i]-'0';
	}
}


int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>str;
		int a=0,b=0,c=0;
		convert(a,b,c);
		if( (a*b)!=0 && c%(a*b)==0){
			printf("Yes\n");
		}else printf("No\n");
	}
} 
