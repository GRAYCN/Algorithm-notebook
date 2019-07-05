//输出应该都没有问题，但是会显示段错误 
#include <cstdio>
#include<iostream>
#include<map>
#include<string>
#define base 13
using namespace std;
string mp[13]={"0","1","2","3","4","5","6","7","8","9","A","B","C"};
map<string,int> marsToEarth;
map<int,string> earthToMars;

void init(){
	for(int i=0;i<13;i++){
		for(int j=0;j<13;j++){
			string str = mp[i]+mp[j];
			earthToMars[i*13+j]=str;
			marsToEarth[str]=i*13+j;
		}
	}
}

int main() {
	init();

	for(int i=0;i<3;i++){
		int temp;
	
		cin>>temp;
		if(i==0) 	cout<<"#";
		cout<<earthToMars[temp];
	}
}
