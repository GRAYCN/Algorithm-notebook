#include<iostream>
#include<cstdio>
#include<map>
#include<string>
#include<cctype>
using namespace std;
map<char,int> mp;
int main(){
	string s1,s2;
//	cin>>s1;
//	cin>>s2;
getline(cin,s1);
getline(cin,s2); 
	//ȫ��ת���ɴ�д 
	for(int i=0;i<s1.length();i++){
		if(mp.find(s1[i])==mp.end()){
			mp[toupper(s1[i])]=1;
		}
	}
	//�����ϵ������
	if(mp.find('+')!=mp.end()){
		for(int i=0;i<s2.length();i++){
			if(s2[i]>='A'&&s2[i]<='Z')
				s2[i]='#';
		}
	}
	for(int i=0;i<s2.length();i++){
		if(mp.find(toupper(s2[i]))==mp.end()){
			if(s2[i]=='#') continue;
			cout<<s2[i];
		}
	}
//	cout<<endl;
	printf("\n");
}
