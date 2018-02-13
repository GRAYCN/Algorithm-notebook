//PATA1129
// multiple mistake
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define maxn 500005
using namespace std;

struct Good{
	int num;
	int id;
}ori[maxn],good[maxn];
int cmp(Good a,Good b){
	if(a.num!=b.num) return a.num>b.num;
	else return a.id<b.id;
}
int main(){
	int N,K;
	cin>>N>>K;
	for(int i=1;i<=N;i++){
		int temp;
		scanf("%d",&temp);
		ori[temp].id=temp;
		ori[temp].num++;
		//		good[temp].id=temp;
		//		ori[temp]++;
		if(i>1){
			for(int i=1;i<=N;i++){
				good[i].id=ori[i].id;
				good[i].num=ori[i].num;
			}
			sort(good+1,good+N+1,cmp);
			printf("%d:",temp);
			int index=1;
			int k=K;
			while(k-- && good[index].num!=0 && index<i){
				printf(" %d",good[index++].id);
			}	
			printf("\n");
		}
	}

}
