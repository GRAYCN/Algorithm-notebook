//A1114
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
using namespace std; 
#define maxn 10000
set<int> s;
int N;

struct Family{
	int ID;
	int father, mother;
	vector<int> child;
	int set;
	int area;
}family[maxn];
struct Group{
	int ID;
	int set;
	int area;
	int family_number;
	double AVG_set;
	double AVG_area;
}group[maxn];
int father[maxn];

void init(){
	for(int i=0;i<maxn;i++){
		father[i]=i;
	}
}

int findFather(int x){
	int a=x;
	while(x!=father[x]){
		x=father[x];
	}
	while(a!=father[a]){
		int z=a;
		a=father[a];
		father[z]=x;
	}
	return x;
}

void Union(int a,int b){
	int fa=findFather(a);
	int fb=findFather(b);
	if(fa!=fb){
		if(fa>fb){
			father[fa]=fb;
		}else{
			father[fb]=fa;
		}
	}
}

int cmp(Group a, Group b){
	if(a.AVG_area!=b.AVG_area){
		return a.AVG_area>b.AVG_area;
	}else return a.ID<b.ID;
}

int main(){
	cin>>N;
	int ID,fath,moth,k,child;
	for(int i=0;i<N;i++){
		cin>>ID>>fath>>moth;
		family[i].ID=ID;
		family[i].father=fath;
		family[i].mother=moth;
		if(fath!=-1)
			Union(ID,fath);
		if(moth!=-1)
			Union(ID,moth);
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>child;
			family[j].child.push_back(child);
			Union(ID,child);
		}
		cin>>family[i].set>>family[i].area;
	}
	
	for(int i=0;i<N;i++){
		int fa=findFather(family[i].ID);
		s.insert(fa); 
		int cnt=1;
		if(family[i].father!=-1) cnt++;
		if(family[i].mother!=-1) cnt++;
		cnt+=family[i].child.size();
		group[fa].ID=fa;
		group[fa].family_number+=cnt;
		group[fa].set+=family[i].set;
		group[fa].area+=family[i].area;
	}
	for(set<int>:: iterator it=s.begin();it!=s.end();it++){
		int index=*it;
		group[index].AVG_set=1.0*group[index].set/group[index].family_number;
		group[index].AVG_area=1.0*group[index].area/group[index].family_number;
	}
	
	printf("%d\n",s.size());
	sort(group,group+s.size(),cmp);
	for(int i=0;i<s.size();i++){
		printf("%04d %d %.3f %.3f\n",group[i].ID,group[i].family_number,group[i].AVG_set,group[i].AVG_area);
	}
}
