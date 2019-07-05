//PATA1063_2
#include<cstdio>
#include<set>
using namespace std;
set<int> a[52],Nc,Nt;

int main(){
	int N,M;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d",&M);
		for(int j=0;j<M;j++){
			int temp;
			scanf("%d",&temp);
			a[i].insert(temp);
		}	
	}
	int K;
	scanf("%d",&K);	
	int p,q;
	for(int i=0;i<K;i++){
		scanf("%d%d",&p,&q);
		int totalNum = a[q].size(), sameNum=0;
		for(auto it=a[p].begin();it!=a[p].end();it++){
			if(a[q].find(*it) != a[q].end()) sameNum++;
			else totalNum++;			
		}
		
		printf("%.1f%\n",sameNum*100.0/totalNum); 
	}
}
