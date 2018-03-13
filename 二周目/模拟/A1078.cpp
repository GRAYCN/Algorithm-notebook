//A1078
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>
using namespace std;
#define maxn 10005
bool hashTable[maxn];

bool isPrime(int n){
	if(n<=1) return false;
	int sqr=(int)sqrt(float(n));
	for(int i=2;i<=sqr;i++){
		if(n%i==0) return false;
	}
	return true;
}


int main(){
	int MSize,N;
	cin>>MSize>>N;
	while(!isPrime(MSize)){
		MSize++;
	}
	for(int i=0;i<N;i++){
		int num,num2;
		cin>>num;
		num2=num;
		int j=1;
		int flag=false;
		while(num2<=MSize){
			if(!hashTable[num2%MSize]){
			hashTable[num2%MSize]=true;
			printf("%d",num2%MSize);
			flag=true;
			if(i!=N-1) printf(" ");
			}else{
				num2=num+j*j;
				j++;
			}	
		}
		if(flag==false){
			printf("-");
			if(i!=N-1) printf(" ");
		} 
	}
}
