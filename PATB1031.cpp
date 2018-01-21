#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int quanzhong[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char mp[11]={'1', '0','X','9','8','7','6','5','4','3','2'};
int main() {
	int N;
	string id;
	cin>>N;
	bool right=true;
	for(int i=0;i<N;i++){
		cin>>id;
		int sum=0;
		int j;
		for(j=0;j<id.length()-1;j++){
			if(id[j]>='0' && id[j]<='9')
				sum+=(id[j]-'0')*quanzhong[j];
			else{
				right=false;
				break;
			}
		}
		if(j<16){		//身份证号码中间有非数字 
			cout<<id<<endl;
		}else{				//进行校验和检查 
			int temp = sum%11;
			if(mp[temp]!=id[17]){
				right=false;
				cout<<id<<endl;
			}
		}
	}
	if(right == true){
		cout<<"All passed"<<endl;
	}
	return 0;
}
