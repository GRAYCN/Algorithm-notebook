#include<iostream>
#include<cstdio>
#include<map>
#include<string>
#include<cctype>
using namespace std;
int bet[100005];
map<int,int> mp;
int main() {
	int N;
	cin>>N;
	int num=0;
	for(int i=0; i<N; i++) {
		cin>>bet[num];
//		if(mp.find(bet[num])==mp.end()) {
//			mp[bet[num]]=1;
//		} 
//		else 
			mp[bet[num]]++;
		num++;
	}
	
	for(int i=0;i<num;i++){
		if(mp.find(bet[i])!=mp.end() && mp[bet[i]]==1){
			cout<<bet[i];
			return 0;
		}
	}
	cout<<"None";

}
