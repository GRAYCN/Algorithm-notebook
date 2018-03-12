//19'
#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<string>
#include<cctype>
using namespace std;
#define maxn 10010
 
char dict[6]={'P','A','T','e','s','t'};
int hashTable[6];

int main(){
	string str;
	cin>>str;
	int length= str.length(),sum=0;
	for(int i=0;i<length;i++){
		for(int j=0;j<6;j++){
			if(str[i]==dict[j]){
				hashTable[j]++;
				sum++;
				continue;
			}
		}
	}
	while(sum>0){
		for(int i=0;i<6;i++){
			if(hashTable[i]>0){
				cout<<dict[i];
				hashTable[i]--;
				sum--;
			}
		}
	}
}
