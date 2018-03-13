//A1019
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
using namespace std;
#define maxn 105
int a[maxn];
int len=0;

bool check(){
	for(int i=0;i<len/2;i++){
		if(a[i]!=a[len-1-i]){
			return false;
		}
	}
	return true;
}

int N,b;
int main(){
	cin>>N>>b;
	do{
		a[len++]=N%b;
		N/=b;
	}while(N);
	if(check()){
		printf("Yes\n");
	}else printf("No\n");
	for(int i=len-1;i>=0;i--){
		printf("%d",a[i]);
		if(i!=0) printf(" ");
	}
} 
