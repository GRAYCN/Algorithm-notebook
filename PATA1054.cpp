#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
	int n,m,col;
	scanf("%d%d",&n,&m);
	map<int,int> count;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
//			cin>>col;
			scanf("%d",&col);
//			if(count.find(col)!=count.end()) count[col]++;
//			else count[col]=1;
			count[col]++;
		}
	}
	int k=0,MAX=0;
	for(map<int,int>::iterator it = count.begin();it!=count.end();it++){
		if(it->second>MAX){
			k=it->first;
			MAX=it->second;
		}
	}
	cout<<k<<endl;
}
