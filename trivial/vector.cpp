//vector
#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> vi;
	for(int i=1;i<=5;i++){
		vi.push_back(i);
	}
	auto it=vi.begin();
	for(int i=0;i<5;i++){
		cout<<*(it+i)<<endl;
	}
	for(it=vi.begin();it!=vi.end();it++){
		cout<<*it<<endl;
	}
} 
