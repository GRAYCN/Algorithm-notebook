//A1015
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
#include <cmath>
using namespace std;
#define maxn 105
int a[maxn];
int len=0;

bool check(int N){
	if(N<=1) return false;
	int sqr=(int)sqrt((float)N);
	for(int i=2;i<=sqr;i++){
		if(N%i==0) return false;
	}
	return true;
}

int N,D;
int main(){
	while(1){
		cin>>N;
		if(N<0) break;
		cin>>D;
		len=0;
		if(check(N)){
			do{
				a[len++]=N%D;
				N/=D;
			}while(N);
			int reverNum=0;
			for(int i=0;i<len;i++){
				reverNum=reverNum*D+a[i];
			}
			if(check(reverNum)){
				printf("Yes\n");
			}else{
				printf("No\n");
			}
		}else{
			printf("No\n");
		}
	}
} 
