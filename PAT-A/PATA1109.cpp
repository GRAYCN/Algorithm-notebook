#include<iostream>
#include<cstdio>
#include <string>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define maxn 10005
int N,K;
struct Student{
	char name[10];
	int height;
}stu[maxn];
vector<string> res;

bool cmp(Student a, Student b){
	if(a.height!=b.height){
		return a.height>b.height;
	}else return strcmp(a.name,b.name)<0;
}

int main(){
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++){
		scanf("%s %d",stu[i].name,&stu[i].height);
	}
	sort(stu,stu+N,cmp);
	//cal the number of the last row
	int lastRowNum = (N%K==0 ? N/K:N/K+N%K);
	res.resize(lastRowNum+1);
	int num=0;
	res[lastRowNum/2+1]=stu[num++].name;
	int j=1;
	while(num<lastRowNum){
		res[lastRowNum/2+1-j]=stu[num++].name;
		if(num<lastRowNum){
			res[lastRowNum/2+1+j]=stu[num++].name;
			j++;
		}

	}
	for(int i=1;i<=res.size()-1;i++){
		//printf("%s",res[i]);
		cout<<res[i];
		if(i<res.size()-1) printf(" ");
	}
	printf("\n");
	int rowNum=N/K;
	res.resize(rowNum+1);
	int cnt=lastRowNum;
	for(int i=0;i<K-1;i++){
		cnt+=rowNum;
		res[rowNum/2+1]=stu[num++].name; 
		while(num<cnt){
			res[rowNum/2+1-j]=stu[num++].name;	
			if(num<cnt){
				res[rowNum/2+1+j]=stu[num++].name;
				j++;
			}

		}
		for(int i=1;i<=res.size()-1;i++){
			//printf("%d",&res[i]);
			cout<<res[i];
			if(i<res.size()-1) printf(" ");
		}
		printf("\n");
		//		num--;
	}
}

/*
10 4
Tom 188
Mike 170
Eva 168
Tim 160
Joe 190
Ann 168
Bob 175
Nick 186
Amy 160
John 159
*/ 
