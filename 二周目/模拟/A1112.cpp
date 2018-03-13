#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
#include <map>
using namespace std;
//#define maxn 
map<char,int> notBroken;
map<char,int> hasOutput;


int main(){
	string str;
	int k;
	cin>>k;
	cin>>str;
	str+='/';
	int cnt=0;
	for(int i=0;i<str.length()-1;i++){
		cnt++;
		if(str[i]!=str[i+1]){
			if( cnt%k!=0 ){
				notBroken[str[i]]=1;				
			}
			cnt=0;
		}
	}
	for(int i=0;i<str.length()-1;i++){
		if(notBroken.find(str[i])==notBroken.end() && hasOutput.find(str[i])==hasOutput.end()){
			cout<<str[i];
			hasOutput[str[i]]=1;
		}
	}
	cout<<endl;
	for(int i=0;i<str.length()-1;i++){
		cout<<str[i];
		if(notBroken.find(str[i])==notBroken.end()){
			i=i+k-1;
		}
	}
}
