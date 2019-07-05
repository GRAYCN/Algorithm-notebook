#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
#define maxn 100010		//这里是为什么呢
bool isPrime(int n){
	if(n<=1) return false;
	int sqr = (int)sqrt(1.0*n);
	for(int i=2;i<=sqr;i++){
		if(n%i==0) return false;
	}
	return true;
}

int prime[maxn],pNum;
void findPrime(){
	for(int i=1;i<maxn;i++){
		if(isPrime(i)){
			prime[pNum++]=i;
		}
	}
}

struct factor{
	int x,cnt;		//x为质因子，cnt为其个数 
}fac[10];
int main(){
	findPrime();
	int n,num;
	cin>>n;
	if(n==1) printf("1=1");			//特判
	else{
		printf("%d=",n);
		int sqr = (int)sqrt(1.0*n);
		for(int i=0;i<pNum && prime[i]<=sqr;i++){
			if(n%prime[i]==0){
				fac[num].x=prime[i];
				fac[num].cnt=0;
				while(n%prime[i]==0){
					fac[num].cnt++;
					n /= prime[i];
				}
				num++;
			}
			// if(n ==1 ) break;
		}
		if(n!=1){
			fac[num].x=n;
			fac[num++].cnt=1;
		}
		for(int i =0;i<num;i++){
			if(i!=0) cout<<"*";
			printf("%d",fac[i].x);
			if(fac[i].cnt>1){
				cout<<"^"<<fac[i].cnt;
			}
		}
	}	
} 
