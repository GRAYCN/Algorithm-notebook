//PATA1015
#include<iostream>
#include<math.h>
using namespace std;
bool isPrime(int n) {
	if(n<=1) return false;
	int sqr = (int)sqrt(n*1.0);
	for(int i=2; i<=sqr; i++) {
		if(n%i==0) return false;
	}
	return true;
}
int d[111];
int main() {
	int n,radix;
	while(scanf("%d",&n)!=EOF) {
		if(n<0) break;
		cin>>radix;
		if(isPrime(n) == false) {
			cout<<"No\n";
		} else {
			int len=0;
			do {
				d[len++] = n%radix;
				n/=radix;
			} while(n!=0);
			for(int i=0;i<len;i++){
				n=n*radix+d[i];
			}
			if(isPrime(n)) cout<<"Yes\n";
			else cout<<"No\n";
		}
	}
}
