//21'
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
vector<string> v;
string mp[10]= {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
string n;
//���±�Ϊ0����ʼ���������������һ��0��λ�� 
int check(int i){
	//	int index = nstr.length()-i;
	while(i!=n.length()-1){
		if(n[i]!='0'){
			return i-1;
		}
		i++; 
	}
	return n.length()-1;
} 
int main() {
	cin>>n;
	if(n=="0"){
		cout<<"ling"<<endl;
		return 0;
	}
	
	if(n[0]=='-') {	//�������
		v.push_back("Fu");
		n.erase(n.begin());
	}

	for(int i=0; i<n.length(); i++) {
		int position=n.length()-i;
		//����0�����
		if(n[i] == '0'){
			//�ӵ�ǰλ��Ѱ��0����ֹλ��next������i��ֵ��next
			//���next������ֹ����Ԫ���ĩβ����ô�������������һ��0��Ȼ��continue 
			int next = check(i);
			i=next;
			if(( position>=5 && position <8 && n.length() - check(i)<5)) 
				v.push_back("Wan");
			if((n.length()-next)%4 == 1){
				continue;
			}else{
				v.push_back("ling");
				continue;
			}
		}
		v.push_back(mp[n[i]-'0']);
		// �����ڣ��� �� ʮ
		if(position%4 == 2) v.push_back("Shi");
		if(position%4 == 3) v.push_back("Bai");
		if(position%4 == 0) v.push_back("Qian");
		if(position == 5 ) 
			v.push_back("Wan");
		if(position == 9) v.push_back("Yi");
	}
	for(int i=0;i<v.size();i++){
		if(i!=0) cout<<" ";
		cout<<v[i];
	}
}
