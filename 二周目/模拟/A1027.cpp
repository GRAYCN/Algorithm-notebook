//A1019
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
using namespace std;
#define maxn 105

char mp[13]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};
string result[169];

void init(){
	int cnt=0;
	for(int i=0;i<13;i++){
		for(int j=0;j<13;j++){
			result[cnt++]=mp[i]+mp[j];
		}
	}
}

int main(){
	init();
	int a,b,c;
	cin>>a>>b>>c;
	cout<<"#"<<result[a]<<result[b]<<result[c];
}
