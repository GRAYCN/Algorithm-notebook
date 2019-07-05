#include <cstdio>
#include <iostream>
using namespace std;
int result[5];
int main() {
	int n;
	cin>>n;
	int num=0;
	do {
		result[num++]=n%10;
		n=n/10;
	} while(n!=0);
	for(int i=0; i<result[2]; i++) {
		cout<<"B";
	}
	for(int i=0; i<result[1]; i++) {
		cout<<"S";
	}
	for(int i=1; i<=result[0]; i++) {
		cout<<i;
	}
}
