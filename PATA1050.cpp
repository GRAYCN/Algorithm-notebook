#include<iostream>
#include<cstdio>
#include<map>
#include<string>
#include<cctype>
using namespace std;
map<char,int> mp;
string s1,s2;
int main() {
	getline(cin,s1);
	getline(cin,s2);
	for(int i=0; i<s2.length(); i++) {
		mp[s2[i]]++;
	}
	for(int i=0; i<s1.length(); i++) {
		if(mp.find(s1[i])==mp.end()) {
			cout<<s1[i];
		}
	}
}
