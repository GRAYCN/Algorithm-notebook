// debug.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	int N;
	string ans;
	scanf("%d\n",&N);
	for(int i=0; i<N; i++) {
		string s;
		getline(cin,s);
		int len=s.length();
		reverse(s.begin(),s.end());
		if(i==0) {
			ans = s;
			continue;
		} else {
			int lenans = ans.length();
			int minlen=min(len,lenans);
			for(int j=0; j<minlen; j++) {
				if(ans[j] != s[j]) {
					ans= ans.substr(0,j);
					break;
				}
			}
		}

	}
	reverse(ans.begin(),ans.end());
	if(ans.length()==0) ans = "nai";
	cout<<ans;
}
