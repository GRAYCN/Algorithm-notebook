#include <stdio.h>
const int N=54;
char mp[5]={'S','H','C','D','J'};
int start[N+1], end[N+1],next[N+1];


int main(){
	int K;
	scanf("%d",&K);
	for(int i=1;i<=N;i++){
		start[i]=i;			//初始化牌的编号 
	}
	for(int i=1;i<=N;i++){
		scanf("%d",&next[i]);		//输入每个位置上的牌在操作后的位置 
	}	
	for(int step=0;step<K;step++){
		for(int i=1;i<=N;i++){
			end[next[i]]=start[i];
		}
		for(int i=1;i<=N;i++){
			start[i]=end[i];
		}	
	}
	for(int i=1;i<=N;i++){
		if(i!=1) printf(" ");
		start[i]--;
		printf("%c%d",mp[start[i]/13],start[i]%13+1);
	}
	return 0;
}
