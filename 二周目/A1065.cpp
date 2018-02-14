//A1065
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
using namespace std;
long long A,B,C,sum;

int main(){
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		scanf("%lld%lld%lld",&A,&B,&C);
		cout<<"Case #"<<i<<": ";
		sum=A+B;
		if(A>0 && B>0 &&(A+B)<=0) cout<<"true";
		else if(A<0 && B<0 &&(A+B)>=0) cout<<"false";
		else if((A+B)>C) cout<<"true";
		else cout<<"false";
		cout<<endl;
	}
}
