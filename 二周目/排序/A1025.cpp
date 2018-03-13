
//A1025
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
#include <cstdio>
using namespace std;

struct Student{
	char number[15];
	int score;
	int final_rank,locak_rank,location_number;
}stu[30005];



int cmp(Student a, Student b){
	if( a.score!= b.score)  return a.score>b.score;
	else return strcmp(a.number,b.number)<0;
}

int N,K;
int nowK;
int cnt;
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		nowK+=K;
		scanf("%d",&K);
		for(int j=0;j<K;j++){
			scanf("%s %d",&stu[cnt].number,&stu[cnt].score);
			stu[cnt].location_number=i+1;
			cnt++;
		}
		sort(stu+nowK,stu+nowK+K,cmp);
		stu[nowK].locak_rank=1;
		for(int i=nowK+1;i<nowK+K;i++){
			if(stu[i].score==stu[i-1].score){
				stu[i].locak_rank=stu[i-1].locak_rank;
			}else{
				stu[i].locak_rank=i-nowK+1;
			}
		}
	}
	sort(stu,stu+cnt,cmp);
	stu[0].final_rank=1;
	for(int i=1;i<cnt;i++){
		if(stu[i].score==stu[i-1].score){
			stu[i].final_rank=stu[i-1].final_rank;
		}else{
			stu[i].final_rank=i+1;
		}
	}
	printf("%d\n",cnt);
	for (int i=0;i<cnt;i++)
	{
		printf("%s %d %d %d\n",stu[i].number,stu[i].final_rank,stu[i].location_number,stu[i].locak_rank);
	}
	
}
