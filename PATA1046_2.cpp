//PATA1046_2
#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAXN 100005

int dis[MAXN],A[MAXN];				//dis数组含义为1号结点按照顺时针方向到达“i号结点顺时针方向的下一个结点” 

int main(){
	int sum=0,query,n,left,right;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i]);
		sum+=A[i];
		dis[i]=sum;		//预处理dis数组 
	} 
	scanf("%d",&query);
	for(int i=0;i<query;i++){
		scanf("%d%d",&left,&right);
		if(left>right) swap(left,right);
		int temp=dis[right-1]-dis[left-1];
		printf("%d\n",min(temp,sum-temp));
	}
	return 0;
}
