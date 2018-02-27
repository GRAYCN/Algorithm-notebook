#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define maxn 10005
int gender[maxn];
int e[maxn][maxn];
vector<int> v[maxn];
int N,M,K;
struct Result{
	int a,b;
}result;
vector<Result> res;

int change(string str){
	bool isNeg=false;
	if(str[0]=='-') {
		isNeg=true;
		str.erase(str.begin());
	}
	int number=0;
	for(int i=0;i<str.length();i++){
		number=number*10+str[i]-'0';
	}
	if(!isNeg){
		gender[number]=1;
	}
	return number;
}

int cmp(Result a, Result b){
	if(a.a!=b.a) return a.a<b.a;
	else return a.b<b.b;
}

int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		string astr,bstr;
		cin>>astr>>bstr;
		int a,b;
		a=change(astr);
		b=change(bstr);
		e[a][b]=e[b][a]=1;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	scanf("%d",&K);
	for(int i=0;i<K;i++){
		string astr,bstr;
		cin>>astr>>bstr;
		int a,b;
		a=change(astr);
		b=change(bstr);
		for(int j=0;j<v[a].size();j++){
			for(int k=0;k<v[b].size();k++){
				int c=v[a][j], d=v[b][k];
				if(c!=b && d!=a){
					if(gender[a]==gender[c] && gender[b]==gender[d]){
						if(e[c][d]){
							result.a=c;
							result.b=d;
							res.push_back(result); 
						}
					}
				}
			}	
		}
		sort(res.begin(),res.end(),cmp);
		printf("%d\n",res.size());
		for(int j=0;j<res.size();j++){
			printf("%04d %04d\n",res[i].a,res[i].b);
		}	
	}
}
