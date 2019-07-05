//the last ceshidian cannot be completed
//PATA1047
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include <string>
using namespace std;
struct Course{
	int num;
	vector<string> v_student;
}cour[2510];

int cmp(string a, string b){
	return a<b;
}

int N,K;
int main(){
	scanf("%d%d",&N,&K);
	string name;
	int number_course;
	for(int i=0;i<N;i++){
		cin>>name>>number_course;
		int index;
		for(int j=0;j<number_course;j++){
			cin>>index;
			cour[index].v_student.push_back(name);
		}
	}
	//sort
	for(int i=1;i<=K;i++){
		cour[i].num=cour[i].v_student.size();
		sort(cour[i].v_student.begin(),cour[i].v_student.end(),cmp);
		printf("%d %d\n",i,cour[i].num);
		for(int j=0;j<cour[i].num;j++){
			cout<<cour[i].v_student[j]<<endl;
		}
	}
}
