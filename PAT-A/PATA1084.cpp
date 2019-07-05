#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<set>
#include<string>
#include<cctype>
using namespace std;
unordered_map<char,int> mp;
int main() {
	string s1,s2;
	cin>>s1;
	cin>>s2;
	//转换为全大写
	for(int i=0; i<s1.length(); i++) {
		s1[i]=toupper(s1[i]);
	}
	for(int i=0; i<s2.length(); i++) {
		s2[i]=toupper(s2[i]);
	}
	for(int i=0; i<s2.length(); i++) {
		if(mp.find(s2[i])==mp.end()) {
			mp[s2[i]]=1;
		}
	}
	for(int i=0;i<s1.length();i++){
		if(mp.find(s1[i])==mp.end()){
			cout<<s1[i];
			mp[s1[i]]=1;
		}
			
	}
}
