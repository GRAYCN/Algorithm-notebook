//A1042
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
using namespace std;

string card[56];
string number[15]={"0","1","2","3","4","5","6","7","8","9","10","11","12","13"};
void init(){
	for(int i=1;i<=13;i++){
		card[i]='S'+number[i];
	}
	for(int i=14;i<=26;i++){
		card[i]='H'+number[i-13];
	}
	for(int i=27;i<=39;i++){
		card[i]='C'+number[i-26];
	}
	for(int i=40;i<=52;i++){
		card[i]='D'+number[i-39];
	}
	card[53]="J1";
	card[54]="J2";
} 

int start[56],next1[56],end1[56];

int main(){
	init();
	int K;
	cin>>K;
	for(int i=1;i<=54;i++){
		start[i]=i;
	}

	for(int i=1;i<=54;i++){
		cin>>next1[i];
	}
	for(int j=0;j<K;j++){
		for(int i=1;i<=54;i++){
			end1[next1[i]]=start[i];
		}
		for(int i=0;i<=54;i++){
			start[i]=end1[i];
		}	
	}
	for(int i=1;i<=54;i++){
		cout<<card[end1[i]];
		if(i!=54) cout<<" ";
	}

}
