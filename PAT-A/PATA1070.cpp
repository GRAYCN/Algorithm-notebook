//PATA1070
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct Mooncake{
	double inventory;
	double price;
	double danjia;
}mooncake[1110];

bool cmp(Mooncake a, Mooncake b){
	return a.danjia>b.danjia;
}

int N,D;
int main(){
	scanf("%d%d",&N,&D);
	for(int i=0;i<N;i++){
		scanf("%lf",&mooncake[i].inventory);
	}
	for(int i=0;i<N;i++){
		scanf("%lf",&mooncake[i].price);
	}
	for(int i=0;i<N;i++){
		mooncake[i].danjia=mooncake[i].price/mooncake[i].inventory;
	}
	sort(mooncake,mooncake+N,cmp);
	int left=D;
	int index=0;
	double profit=0;
	while(left>0 && index<N){
		if(left>=mooncake[index].inventory){
			profit+=mooncake[index].price;
			left-=mooncake[index].inventory;
		}else{
			profit+=left*mooncake[index].danjia;
			left=0;
		}
		index++;
	}
	printf("%.2f",profit);
} 
