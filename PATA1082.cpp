//21'
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
vector<string> v;
string mp[10]= {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
string n;
//从下标为0处开始向后遍历，返回最后一个0的位置 
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
	
	if(n[0]=='-') {	//处理符号
		v.push_back("Fu");
		n.erase(n.begin());
	}

	for(int i=0; i<n.length(); i++) {
		int position=n.length()-i;
		//处理0的情况
		if(n[i] == '0'){
			//从当前位置寻找0的终止位置next，并将i赋值给next
			//如果next正好终止于四元组的末尾，那么不读，否则读入一个0，然后continue 
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
		// 处理亿，万 百 十
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
