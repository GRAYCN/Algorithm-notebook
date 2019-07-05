#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
	stack<string> v;
	string str;
	while(cin>>str) {
		v.push(str);
	}
	cout<<v.top();
	v.pop();
	while(!v.empty()) {
		cout<<" ";
		cout<<v.top();
		v.pop();
	}
}
