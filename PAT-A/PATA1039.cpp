//PATA1039
#include <cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include <vector>
#define N 40005
#define M 26*26*26*10 + 1
using namespace std;

vector<int> selectCourse[M];
//字符串散列函数
int getID(char name[]){
	int id=0;
	for(int i=0;i<3;i++){
		id=id*26+(name[i]-'A');
	}
	id=id*10+(name[3]-'0');
	return id;
} 

int main(){
	char name[5];
	int n,k;
	scanf("%d%d",&n,&k);
//	cin>>n>>k;
	for(int i=0;i<k;i++){
		int course,x;
		scanf("%d%d",&course,&x);
//		cin>>course>>x;
		for(int j=0;j<x;j++){
			scanf("%s",name);	//输入选课学生名
//			cin>>name;
			int id = getID(name);
			selectCourse[id].push_back(course); 
		}
	}
	//读取查询列表并输出
	for(int i=0;i<n;i++){
		scanf("%s",name);
//		cin>>name;
		int id = getID(name);
		sort(selectCourse[id].begin(),selectCourse[id].end());
		printf("%s %d",name,selectCourse[id].size());
		for(int j=0;j<selectCourse[id].size();j++){
			printf(" %d",selectCourse[id][j]);
		}
		printf("\n");
	} 
}


