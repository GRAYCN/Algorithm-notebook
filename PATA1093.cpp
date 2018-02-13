//PATA1093
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define maxn 100005
string s;
int leftP[maxn],rightT[maxn];			//记录下标为 i的位置的右侧P的数目和左侧的T的数目
int main() {
	getline(cin,s);
	//从左往右找P
	for(int i=0; i<s.length(); i++) {
		if(s[i]=='P') {
			leftP[i+1]++;
		}
	}
	//从右往左找T

	long long count=0;
	for(int i=s.length(); i>=0; i--) {
		if(s[i]=='T' && i!=0) {		//加一个条件，防止数组越界
			rightT[i-1]++;

		}
		if(s[i]=='A') {
			count+=rightT[i]*leftP[i];
		}
	}
	cout<<count%1000000007;
}
