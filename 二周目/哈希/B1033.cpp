//19'
#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<string>
#include<cctype>
using namespace std;
map<char,int> mp;
int main() {
	string s1,s2;
	cin>>s1;
	cin>>s2;
	for(int i=0;i<s1.length();i++){
		mp[toupper(s1[i])]=1; 
	}
	for(int i=0;i<s2.length();i++){
		if(mp[toupper(s2[i])]){
			continue; 
		}
		if(mp['+'] && (s2[i]>='A' && s2[i]<='Z')){
			continue;
		}
		if(mp[s2[i]]){
			continue;
		} 
		cout<<s2[i];
	}
	printf("\n");
}
