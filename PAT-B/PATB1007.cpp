//PATB1007

#include<iostream>
#include<math.h>
using namespace std;

bool isPrime(int n){
	if(n<=1) return false;
	int sqr = (int)sqrt(1.0*n);
	for(int i=2;i<=sqr;i++){
		if(n%i == 0) return false;
	}
	return true;
}

int main(){
	int n, count = 0;
	cin>>n;
	for(int i=3;i+2<=n;i++){
		if(isPrime(i) && isPrime(i+2)){
			count++;
		}
	}
	cout<<count;
}
