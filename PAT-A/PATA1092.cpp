#include<iostream>
#include<cstdio>
#include<map>
#include<string>
#include<cctype>
using namespace std;
map<char,int> mp1;
map<char,int> mp2;
int main() {
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	for(int i=0; i<s1.length(); i++) {
		if(mp1.find(s1[i])==mp1.end()) {
			mp1[s1[i]]=1;
		} else mp1[s1[i]]++;
	}
	for(int i=0; i<s2.length(); i++) {
		if(mp2.find(s2[i])==mp2.end()) {
			mp2[s2[i]]=1;
		} else mp2[s2[i]]++;
	}
	bool flag=true;		//��¼�ܷ�����Ҫ��
	for(auto it=mp2.begin(); it!=mp2.end(); it++) {
		if(mp1.find(it->first)==mp1.end() || mp1[it->first] < it->second) {
			flag=false;
			break;
		}
	}
	//��������򣬱���Mp1��ͼ�ȥmp2��� ��������
	if(flag==true) {
		cout<<"Yes ";
		int sum1=0,sum2=0;
		for(auto it=mp1.begin(); it!=mp1.end(); it++) {
			sum1+=it->second;
		}
		for(auto it=mp2.begin(); it!=mp2.end(); it++) {
			sum2+=it->second;
		}
		cout<<sum1-sum2;
	} else { //�����������mp2��ͼ�ȥMp2��mp1�ж�Ӧ�±�ĺͣ� ���
		cout<<"No ";
		int sum=0;
		//����ֱ�����
		for(auto it=mp2.begin(); it!=mp2.end(); it++) {
			if(mp1.find(it->first)==mp1.end()) {
				sum+=it->second;
			} else if(mp1[it->first]<it->second) {
				sum+=it->second - mp1[it->first];
			}
		}
		cout<<sum;
	}
}
//}
