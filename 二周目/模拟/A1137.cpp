//A1137
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
#define maxn 30005
map<string,int> strToInt;
map<int,string> intToStr;

struct Student{
	string ID;
	int Gp,Gm,Gf,G;		 
	Student(){
		Gp=Gm=Gf=-1;
	}
}student[maxn];

vector<Student> v;

int P,M,N;

int cmp(Student a, Student b){
	if(a.G!=b.G) return a.G>b.G;
	else return a.ID<b.ID;
}

int main(){
	cin>>P>>M>>N;
	string id;
	int score;
	int num=0;
	for(int i=0;i<P;i++){
		cin>>id>>score;
		if(strToInt.find(id)==strToInt.end()){
			strToInt[id]=num;
			intToStr[num]=id;
			num++;	
		}
		student[strToInt[id]].ID=id;
		student[strToInt[id]].Gp=score;
	}
	for(int i=0;i<M;i++){
		cin>>id>>score;
		if(strToInt.find(id)==strToInt.end()){
			strToInt[id]=num;
			intToStr[num]=id;
			num++;	
		}
		student[strToInt[id]].ID=id;
		student[strToInt[id]].Gm=score;
	}
	for(int i=0;i<N;i++){
		cin>>id>>score;
		if(strToInt.find(id)==strToInt.end()){
			strToInt[id]=num;
			intToStr[num]=id;
			num++;	
		}
		student[strToInt[id]].ID=id;
		student[strToInt[id]].Gf=score;
	}

	for(int i=0;i<num;i++){
		if(student[i].Gm>student[i].Gf){
			student[i].G=(double)student[i].Gm*0.4+(double)student[i].Gf*0.6+0.5;
		}else{
			student[i].G=student[i].Gf;
		}
		if (student[i].ID=="dx86w")
		{
			printf("");
		}
		if(student[i].Gp>=200 && student[i].G>=60){
			v.push_back(student[i]);
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++){
		cout<<v[i].ID;
		printf(" %d %d %d %d\n",v[i].Gp,v[i].Gm,v[i].Gf,v[i].G);
	}

}
