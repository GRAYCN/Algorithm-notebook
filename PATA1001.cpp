#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	int a,b,c;
	cin>>a>>b;
	c=a+b;
	if(c<0) {
		cout<<'-';
		c=-c;
	}
	string cstr=to_string(c);
	for(int i=0;i<cstr.length();i++){
		cout<<cstr[i];
		if((cstr.length()-i-1)%3==0 && (cstr.length()-i-1)!=0 ){
			cout<<',';
		}
	}	
} 
