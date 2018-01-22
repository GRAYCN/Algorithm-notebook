#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int c[105];
char mp[13]= {'0','1','2','3','4','5','6','7','8','9','J','Q','K'};
int main() {
	string a,b;
	cin>>a>>b;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	//B is shorter than or equal to A,对B的长度进行遍历即可
	if(b.length()<=a.length()) {
		b.append(a.length()-b.length(),'0');
	} else a.append(b.length()-a.length(),'0');
	for(int i=0; i<b.length(); i++) {
		if(i%2==0) {			//实际是奇数位
			c[i]=(a[i]-'0'+b[i]-'0')%13;
		} else {				//实际是偶数位
			c[i]=b[i]-a[i];
			if(c[i]<0) {
				c[i]+=10;
			}
		}
	}

	for(int i=b.length()-1; i>=0; i--) {
		cout<<mp[c[i]];
	}


}
