#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string mp[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
int a[100];

int main(){
	string n;
	cin>>n;
	int sum=0;
	for(int i=0;i<n.length();i++){
		sum += n[i]-'0';
	}
	int len=0;
	do{
		a[len++]=sum%10;
		sum/=10;
	}while(sum);
	for(int i=len-1;i>=0;i--){
		cout<<mp[a[i]];
		if(i!=0) printf(" ");
	}
}
