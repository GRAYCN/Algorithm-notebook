//PATA1093
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define maxn 100005
string s;
int leftP[maxn],rightT[maxn];			//��¼�±�Ϊ i��λ�õ��Ҳ�P����Ŀ������T����Ŀ
int main() {
	getline(cin,s);
	//����������P
	for(int i=0; i<s.length(); i++) {
		if(s[i]=='P') {
			leftP[i+1]++;
		}
	}
	//����������T

	long long count=0;
	for(int i=s.length(); i>=0; i--) {
		if(s[i]=='T' && i!=0) {		//��һ����������ֹ����Խ��
			rightT[i-1]++;

		}
		if(s[i]=='A') {
			count+=rightT[i]*leftP[i];
		}
	}
	cout<<count%1000000007;
}
