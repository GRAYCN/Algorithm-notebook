#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string mp[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
int main(){
	string n;
	cin>>n;
	int sumn=0;
	for(int i=0;i<n.length();i++){
		sumn+=n[i]-'0';
	}
	string sumnstr=to_string(sumn);
	for(int i=0;i<sumnstr.length();i++){
		if(i!=0) cout<<" ";
		cout<<mp[sumnstr[i]-'0'];
	}
}
