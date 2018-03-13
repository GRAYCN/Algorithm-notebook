//A1077
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
#include <cmath>
using namespace std;

int n,minLen=256,ans=0;//至多有100个字符串，每个字符串至多有256个字符 

int main(){
	scanf("%d",&n);
	getchar();	//吞下换行符 
	for(int i=0;i<n;i++){
		gets(s[i]);	
		int len = strlen(s[i]);
		if(len<minLen) minLen=len;
		reverse(s[i],s[i]+len);

	} 
	for(int i=0;i<minLen;i++){
		char c = s[0][i];
		bool same=true;
		for(int j=1;j<n;j++){
			if(c!=s[j][i]){
				same=false;
				break;
			}
		}
		if(same) ans++;
		else break;
	}
	if(ans){
		for(int i=ans-1;i>=0;i--){
			printf("%c",s[0][i]);
		}
	}else{
		printf("nai");
	}
}
