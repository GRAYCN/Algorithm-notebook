//PATA1112 
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include<cstdio>
using namespace std;

int stuck[256];
char str[1002];
bool p[256];
int main(){
	int k;
	scanf("%d",&k);
	scanf("%s",str);
	int times=1;
	for(int i=1;str[i-1];++i){		// why str[i-1]? in order to handle the last char
		if(str[i]!=str[i-1]){
			if(times%k!=0){
				stuck[str[i-1]]= -1;		//the key of str[i-1] is impossible to stuck
			}else if(stuck[str[i-1]] != -1){
				stuck[str[i-1]]= 1;
			}
			times=1;
		}else{
			times++;
		}
	}
	for(int i=0;str[i];++i){
		if(stuck[str[i]]==1 && p[str[i]]==false){
			putchar(str[i]);
			p[str[i]]=true;
		}
	}
	putchar('\n');
	for(int i=0;str[i];i++){
		putchar(str[i]);
		if(stuck[str[i]]==1){
			i+=k-1;
			continue;
		}
	}
}
