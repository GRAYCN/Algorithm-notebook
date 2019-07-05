//PATA1116
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
#define maxn 10005
struct Student{
	int rank;
	bool hasChecked;
}stu[maxn];

bool visit[maxn];

bool isPrime(int x){
	if(x==1) return false;
	for(int i=2;i<=sqrt((double)x);i++){
		if(x%i==0) return false;
	}
	return true;
}


int main(){
	int N,K;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		int index;
		cin>>index;
		stu[index].rank=i;
		visit[index]=true;
	}
	cin>>K;
	for(int i=0;i<K;i++){
		int query;
		cin>>query;
		if(!visit[query]){
			printf("%04d: Are you kidding?\n",query);
		}else{
			if(stu[query].hasChecked){
				printf("%04d: Checked\n",query);
			}else{
				if(stu[query].rank==1){
					printf("%04d: Mystery Award\n",query);
					stu[query].hasChecked=true;
				}else if(isPrime(stu[query].rank)){
					printf("%04d: Minion\n",query);
					stu[query].hasChecked=true;
				}else{
					printf("%04d: Chocolate\n",query);
					stu[query].hasChecked=true;	
				}
			}
		}
	}
}
