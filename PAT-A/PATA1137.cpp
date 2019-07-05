//19' 
//PATA1137
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include <cmath>
using namespace std;
struct Student{
	string id;
	int Gp,Gm,Gf;
	int G;
	int output;
	Student(){
		Gp=Gm=Gf=-1;
	}
}stu[30005];
map<string,int> strToint;

int cmp(Student a,Student b){
	if(a.output!=b.output) return a.output>b.output;
	else if(a.G!=b.G) return a.G>b.G;
	else return a.id<b.id;
}

int main(){
	int P,M,N;
	cin>>P>>M>>N;
	string id;
	int score;
	int cnt=0;
	for(int i=0;i<P;i++){
		cin>>id>>score;
		if(strToint.find(id)==strToint.end()){
			strToint[id]=cnt++;
		}
		int index=strToint[id];
		stu[index].id=id;
		stu[index].Gp=score;
	}

	for(int i=0;i<M;i++){
		cin>>id>>score;
		if(strToint.find(id)==strToint.end()){
			strToint[id]=cnt++;
		}
		int index=strToint[id];
		stu[index].id=id;
		stu[index].Gm=score;
	}

	for(int i=0;i<N;i++){
		cin>>id>>score;
		if(strToint.find(id)==strToint.end()){
			strToint[id]=cnt++;
		}
		int index=strToint[id];
		stu[index].id=id;
		stu[index].Gf=score;
	}

	for(int i=0;i<cnt;i++){
		
		if(stu[i].Gm>stu[i].Gf){
				//stu[i].G=ceil((float)stu[i].Gm*0.4+(float)stu[i].Gf*0.6);
			stu[i].G=int(stu[i].Gm * 0.4 + stu[i].Gf * 0.6 + 0.5);
		}else{
			stu[i].G=stu[i].Gf;
		}
		if(stu[i].Gp>=200 && stu[i].G>=60){
			stu[i].output=1;
		}
	}

	sort(stu,stu+cnt,cmp);
	for(int i=0;i<cnt;i++){
		if(stu[i].output==1){
			cout<<stu[i].id;
			printf(" %d %d %d %d\n",stu[i].Gp,stu[i].Gm,stu[i].Gf,stu[i].G);
		}
	}
}

