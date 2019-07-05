#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<string>
#include<cctype>
using namespace std;
unordered_map<char,int> mp;
char ch[6]= {'P','A','T','e','s','t'};
//³õÊ¼»¯º¯Êý
void init() {
	for(int i=0; i<6; i++) {
		mp[ch[i]]=0;
	}
}
int main() {
	string s;
	init();
	getline(cin,s);
	int sum=0;
	for(int i=0;i<s.length();i++){
		if(mp.find(s[i])!=mp.end()){
			mp[s[i]]++;
			sum++;
		}
	}
	while(sum){
		for(int i=0;i<6;i++){
			if(mp[ch[i]]){
				cout<<ch[i];
				mp[ch[i]]--;
				sum--;
				if(sum==0) break;
			}
		}
	}
}
