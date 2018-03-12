#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<string>
#include<cctype> 
using namespace std;
map<char,int> mp1,mp2;
int main() {
	string s1,s2;
	cin>>s1>>s2;
	for(int i=0;i<s1.length();i++){
		mp1[s1[i]]++;
	}
	for(int i=0;i<s2.length();i++){
		mp2[s2[i]]++;
	}
	int flag=true;
	for(auto it=mp2.begin();it!=mp2.end();it++){
		if(mp1[it->first]<it->second){
			flag=false;
			break;
		}
	}
	if(flag==true){
		int sum1=0,sum2=0;
		for(auto it=mp1.begin();it!=mp1.end();it++){
			sum1+=it->second;		
		}
		for(auto it=mp2.begin();it!=mp2.end();it++){
			sum2+=it->second;		
		}
		printf("Yes %d",sum1-sum2);
	}else{
		int sum=0;
		for(auto it=mp2.begin();it!=mp2.end();it++){
			if(mp1[it->first]<it->second){
				sum+=it->second-mp1[it->first];
			}
		}
		printf("No %d",sum);
		
	}
}
