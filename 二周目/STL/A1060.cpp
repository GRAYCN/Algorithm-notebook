//A1060
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
using namespace std;
int N;
string A,B;
string strA,strB,resultA,resultB;
int main(){
	cin>>N>>A>>B;
	//compute the zhengshu digit of A
	int numA=0,numB=0;
	
	while(numA<A.length() && A[numA]!='.'){
		numA++;
	}
	while(numB<B.length() && B[numB]!='.'){
		numB++;
	}
	for(int i=0;i<N;i++){
		if(i<A.length()){
			strA+=A[i];
		}else{
			strA+='0';
		}
	}
	for(int i=0;i<N;i++){
		if(i<B.length()){
			strB+=B[i];
		}else{
			strB+='0';
		}
	}
	if(strA==strB && numA==numB){
		printf("YES ");
		cout<<"0."<<strA<<"*10^"<<numA;
	}else{
		printf("NO ");
		cout<<"0."<<strA<<"*10^"<<numA<<" ";
		cout<<"0."<<strB<<"*10^"<<numB;
	}
}
