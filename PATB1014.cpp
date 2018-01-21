#include <iostream>
#include <string>
using namespace std;
string w[9]={"MON","TUE","WED","THU","FRI","SAT","SUN"};		//星期字符串
 
int main() {
	string a,b,c,d;
	int first,second,third;
	cin>>a>>b>>c>>d;
//	scanf("%s%s%s%s",a,b.c_str(),c.c_str(),d.c_str());
	for(int i=0;;i++){
		if(a[i]==b[i]&&a[i]>='A'&&a[i]<='G'){
			first=i;		//记录第一对相同的大写英文字母的位置 
			break;
		}
	}
	for(int i=first+1;;i++){
		if(a[i]==b[i] && (a[i]>='A'&&a[i]<='N' || a[i]>='0' && a[i]<='9')){
			second=i;	//记录第二对相同的符号的位置 
			break;
		}
	}
	
	//寻找第三对相同的位置
	for(int i=0;;i++){
		if(c[i]==d[i] && c[i]>='A' && c[i]<='z'){
			third=i;
			break;
		}
	} 
	//处理小时问题
	int hh;
	if(a[second]>='0' && a[second]<='9'){
		hh=a[second]-'0';
	} else{
		hh='9'-'0'+1+a[second]-'A';
	}
	printf("%s %02d:%02d",w[a[first]-'A'].c_str(),hh,third);
	
	
}
