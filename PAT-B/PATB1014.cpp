#include <iostream>
#include <string>
using namespace std;
string w[9]={"MON","TUE","WED","THU","FRI","SAT","SUN"};		//�����ַ���
 
int main() {
	string a,b,c,d;
	int first,second,third;
	cin>>a>>b>>c>>d;
//	scanf("%s%s%s%s",a,b.c_str(),c.c_str(),d.c_str());
	for(int i=0;;i++){
		if(a[i]==b[i]&&a[i]>='A'&&a[i]<='G'){
			first=i;		//��¼��һ����ͬ�Ĵ�дӢ����ĸ��λ�� 
			break;
		}
	}
	for(int i=first+1;;i++){
		if(a[i]==b[i] && (a[i]>='A'&&a[i]<='N' || a[i]>='0' && a[i]<='9')){
			second=i;	//��¼�ڶ�����ͬ�ķ��ŵ�λ�� 
			break;
		}
	}
	
	//Ѱ�ҵ�������ͬ��λ��
	for(int i=0;;i++){
		if(c[i]==d[i] && c[i]>='A' && c[i]<='z'){
			third=i;
			break;
		}
	} 
	//����Сʱ����
	int hh;
	if(a[second]>='0' && a[second]<='9'){
		hh=a[second]-'0';
	} else{
		hh='9'-'0'+1+a[second]-'A';
	}
	printf("%s %02d:%02d",w[a[first]-'A'].c_str(),hh,third);
	
	
}
