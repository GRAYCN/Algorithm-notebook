#include<iostream>
#include<cstdio>
#include<map>
#include<string>
#include<cctype>
#include<algorithm>
#define maxn 100005
using namespace std;
map<int,int> mp;
int a[maxn];
int N,M;
int main(){
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>a[i];
		mp[a[i]]++; 
	}
	sort(a,a+N);
	for(int i=0;i<N;i++){
		//如果M-a[i]在mp中能找到并且值大于等于1，则输出
		mp[a[i]]--;
		int temp=M-a[i];
		if(mp[temp]>=1){
			cout<<a[i]<<" "<<temp;
			return 0;
		}
		mp[a[i]]++; 
	}
	cout<<"No Solution";
	
}
