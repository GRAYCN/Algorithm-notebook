#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 100005
int N,M;
int a[maxn];
int sum[maxn];
int nearS=(1<<9);

int main(){
	cin>>N>>M;
	for(int i=1;i<=N;i++){
		cin>>sum[i];
		sum[i]+=sum[i-1];		//记录下标为i为止的价值总和 
	}
	for(int i=1;i<=N;i++){
		//查看是否满足sum[j]-sum[i-1]==M 即[i,j]区间范围内的和是S
		//也就是说在sum中找到这样一个下标j，使得M+sum[i-1]>sum[j]首次成立 
		int j=upper_bound(sum+i,sum+N+1,sum[i-1]+M)-sum;
		//如果找到的[i,j-1]刚好使得价值之和为M
		if(sum[j-1] - sum[i-1] == M){
			nearS=M;			//最接近M的就是M; 
			break;
		}
		//否则找到使得  sum[j-1] - sum[i-1] 最接近M的数作为NesrS
		else{
			if(j<=N && (sum[j] - sum[i-1]) < nearS){
				nearS=sum[j] - sum[i-1];		//这里使用j而不是j-1，原因需要好好体会 
			}
		} 
	}

	for(int i=1;i<=N;i++){
		int j=upper_bound(sum+i,sum+N+1,sum[i-1]+nearS)-sum;
		if(sum[j-1]-sum[i-1]==nearS){

			printf("%d-%d\n",i,j-1);
		}
	}
}
