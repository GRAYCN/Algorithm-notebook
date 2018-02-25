#include<iostream>
#include<cstdio>
#include<map>
#include<string>
#include<cctype>
#include<algorithm>
#define maxn 101
using namespace std;
map<int,int> mp;

int K;
int a[maxn];

int cmp(int a,int b){
	return a>b;
}

int main(){
	cin>>K;
	for(int i=0;i<K;i++){
		cin>>a[i];
		//		mp[a[i]]=0;
	}
	for(int i=0;i<K;i++){
		int temp=a[i];
		//mp[temp]++;
		do{
			if(temp%2==0)		//Å¼Êý
			{
				temp/=2;
			} else{		//ÆæÊý 
				temp=(3*temp+1)/2;
			} 
			mp[temp]++;
		}while(temp!=1);
	}
	sort(a,a+K,cmp);
	int num=0;
	for(int i=0;i<=K-1;i++){
		if(mp.find(a[i])==mp.end()){
			num++;
			if(num!=1) cout<<" ";
			cout<<a[i]; 
		}
	}

}
