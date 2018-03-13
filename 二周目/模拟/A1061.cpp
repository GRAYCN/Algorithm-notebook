//A1061
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <map>
using namespace std;
map<int,string> Day;
int hour[256];
void init(){
	Day['A']="MON";
	Day['B']="TUE";
	Day['C']="WED";
	Day['D']="THU";
	Day['E']="FRI";
	Day['F']="SAT";
	Day['G']="SUN";
	hour['0']=0;
	hour['1']=1;
	hour['2']=2;
	hour['3']=3;
	hour['4']=4;
	hour['5']=5;
	hour['6']=6;
	hour['7']=7;
	hour['8']=8;
	hour['9']=9;
	hour['A']=10;
	hour['B']=11;
	hour['C']=12;
	hour['D']=13;
	hour['E']=14;
	hour['F']=15;
	hour['G']=16;
	hour['H']=17;
	hour['I']=18;
	hour['J']=19;
	hour['K']=20;
	hour['L']=21;
	hour['M']=22;
	hour['N']=23;
}

int main(){
	string str1,str2,str3,str4;
	init();
	cin>>str1>>str2>>str3>>str4;
	int i;
	for(i=0;i<str1.length();i++){
		if(str1[i]==str2[i]){
			if(str1[i]>='A' && str1[i]<='G'){
				cout<<Day[str1[i]];	
				break;			
			}
		}
	}	
	for(i++;i<str1.length();i++){
		if(str1[i]==str2[i]){
			if( (str1[i]>='0'&&str1[i]<='9') || (str1[i]>='A' && str1[i]<='N') ){
				//				cout<<hour[str1[i]];	
				printf(" %02d:",hour[str1[i]]);
				break;			
			}
		}
	}
	for(i=0;i<str3.length();i++){
		if(str3[i]==str4[i]){
			if((str3[i]>='a' && str3[i]<='z' )|| (str3[i]>='A' && str3[i]<='Z') ){

				printf("%02d",i);
				break;
			}
		}
	}
}

