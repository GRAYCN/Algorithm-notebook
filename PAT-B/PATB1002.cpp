#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string mp[12]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

int main(){
	string n;
	cin>>n;	
	int sum=0;
	for(int i=0;i<n.length();i++){
		sum+=(n[i]-'0');
	}
	int csum[100],num=0;
	do{
		csum[num++]=sum%10;
		sum/=10;
	}while(sum!=0);
	for(int i=num-1;i>=0;i--){
		cout<<mp[csum[i]];
		if(i!=0){
			cout<<" ";
		}
	}
//	cout<<sum<<endl;
}
