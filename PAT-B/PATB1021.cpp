#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int count[10];
int main() {
	string N;
	cin>>N;
//	printf("%d",&N);
for(int i=0;i<N.length();i++){
	char temp=N[i];
	count[temp-'0']++;
}
	for(int i=0;i<=9;i++){
		if(count[i]!=0){
			printf("%d:%d\n",i,count[i]);
		}
	}
}
