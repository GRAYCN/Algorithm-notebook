//δ����������� 
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
vector<string> v;
string mp[10]= {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
string nstr;
//���±�Ϊ0����ʼ���������������һ��0��λ�� 
int check(int i){
//	int index = nstr.length()-i;
	while(i!=nstr.length()-1){
		if(nstr[i]!='0'){
			return i-1;
		}
		i++; 
	}
} 
int main() {
	int n;
	cin>>n;
	if(n<0) {	//�������
		v.push_back("Fu");
		n=-n;
	}
	if(n==0)
		v.push_back("ling");
	nstr=to_string(n);
	for(int i=0; i<nstr.length(); i++) {
		//����0�����
		if(nstr[i] == '0'){
			//�ӵ�ǰλ��Ѱ��0����ֹλ��next������i��ֵ��next
			//���next������ֹ����Ԫ���ĩβ����ô�������������һ��0��Ȼ��continue 
			 int next = check(i);
			 i=next; 
			 if((nstr.length()-next)%4 == 1){
			 	continue;
			 }else{
			 	v.push_back("ling");
			 	continue;
			 }
		}
		v.push_back(mp[nstr[i]-'0']);
		// �����ڣ��� �� ʮ
		int index = nstr.length()-i;
		if(index%4 == 2) v.push_back("Shi");
		else  if(index%4 == 3) v.push_back("Bai");
		else  if(index%4 == 0) v.push_back("Qian");
		else  if(index == 5) v.push_back("Wan");
		else  if(index == 9) v.push_back("Yi");
	}
	for(int i=0;i<v.size();i++){
		if(i!=0) cout<<" ";
		cout<<v[i];
	}
}
