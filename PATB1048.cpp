//��������Ȼ�������� 
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int c[105];
char mp[13]={'0','1','2','3','4','5','6','7','8','9','J','Q','K'};
int main() {
	string a,b;
	cin>>a>>b;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	//B is shorter than A,��B�ĳ��Ƚ��б�������
	for(int i=0; i<b.length(); i++) {
		if(i%2==0) {			//ʵ��������λ
			c[i]=(a[i]-'0'+b[i]-'0')%13;
		} else {				//ʵ����ż��λ
			c[i]=b[i]-a[i];
			if(c[i]<0) {
				c[i]+=10;
			}
		}
	}

	//B is longer than A
	//�ȱ���A�ĳ��ȵĴ�
	int i;
	for(i=0; i<a.length(); i++) {
		if(i%2==0) {			//ʵ��������λ
			c[i]=(a[i]-'0'+b[i]-'0')%13;
		} else {				//ʵ����ż��λ
			c[i]=b[i]-a[i];
			if(c[i]<0) {
				c[i]+=10;
			}
		}
	}
	//��B����A�Ĳ���ֱ�Ӹ�ֵ��c
	for(; i<b.length(); i++) {
		c[i]=b[i]-'0';
	}
	for(int i=b.length()-1;i>=0;i--){
		cout<<mp[c[i]];
	}
	
	
}
