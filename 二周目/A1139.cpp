//A1139
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
#include <vector> 
#define maxn 10000
using namespace std;
struct Student{
	int gender;	//1 boy 0 girl
	vector<int> Friend;
}stu[maxn];
struct Result{
	int id1;
	int id2;
}result;
vector<Result> res;
int e[maxn][maxn];
int N,M;
int convert(string str){
	if(str[0]=='-'){
		str.erase(str.begin());
	}
	int a=0;
	for(int i=0;i<str.length();i++){
		a=a*10+(str[i]-'0');
	}
	return a;
}

int cmp(Result a,Result b){
	if(a.id1!=b.id1) return a.id1<b.id1;
	else return a.id2<b.id2;
}

int main(){
	cin>>N>>M;
	for(int i=0;i<M;i++){
		string id1,id2;
		cin>>id1>>id2;
		int a,b;
		a=convert(id1);
		b=convert(id2);
		e[a][b]=e[b][a]=1;
		stu[a].Friend.push_back(b);
		stu[b].Friend.push_back(a);
		if(id1[0]=='-'){
			stu[a].gender=0;
		}else stu[a].gender=1;
		if(id2[0]=='-'){
			stu[b].gender=0;
		}else stu[b].gender=1;
	}
	int K;
	cin>>K;
	for(int i=0;i<K;i++){
		int a,b;
		cin>>a>>b;
		if(a<0) a=-a;
		if(b<0) b=-b;
		res.clear();
		for(int j=0;j<stu[a].Friend.size();j++){ 
			for(int k=0;k<stu[b].Friend.size();k++){
				int id1=stu[a].Friend[j];
				int id2=stu[b].Friend[k];
				if(stu[id1].gender==stu[a].gender &&stu[id2].gender==stu[b].gender && id1!=b &&id2!=a ){
					if(e[id1][id2]==1){
						result.id1=id1;
						result.id2=id2;
						res.push_back(result);
					}
				}
			}	
		}
		sort(res.begin(),res.end(),cmp);
		printf("%d\n",res.size());
		for(int j=0;j<res.size();j++){
			printf("%04d %04d\n",res[j].id1,res[j].id2);
		}
	}	
}
