#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
vector<string> svec1;			//记录所有编辑过的字符串 
vector<string> svec2;			//记录所有编辑过的字符串 
int main(){
	int N;
	string str1,str2;
	cin>>N;
	int count=0;		//记录需要修改的 
	for(int i=0;i<N;i++){
		cin>>str1>>str2;
		if(!(str2.find('1')==-1 && str2.find('0')==-1 && str2.find('l')==-1 && str2.find('O')==-1 ) )		//如果存在需要替换的字符 
		{
			for(int i=0;i<str2.length();i++){
				if(str2[i]=='1') str2[i]='@';
				else if(str2[i]=='0')  str2[i]='%';
				else if(str2[i]=='l') str2[i]='L';
				else if(str2[i]=='O') str2[i]='o';
			}
			svec1.push_back(str1);
			svec2.push_back(str2);
		}
	}
	if(svec1.size()!=0){
		cout<<svec1.size()<<endl;
		for(int i=0;i<svec1.size();i++){
			cout<<svec1[i]<<" "<<svec2[i]<<endl;
		}
	}else{
		if(N==1){
			printf("There is 1 account and no account is modified");
		}
		else
		printf("There are %d accounts and no account is modified",N);
	}
}
