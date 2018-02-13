//PATA1068_2
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=10010;
const int maxv=110;
int w[maxn],dp[maxv];
bool choice[maxn][maxv], flag[maxn];
bool cmp(int a, int b){
	return a>b;
}

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	sort(w+1, w+n+1, cmp);
	for(int i=1;i<=n;i++){
		for(int v=m;v>=w[i];v--){
			if(dp[v]<=dp[v-w[i]]+w[i]){
				dp[v]=dp[v-w[i]]+w[i];
				choice[i][v] =1;
			}
			else choice[i][v]=0;
		}
	}
	if(dp[m]!=m) cout<<"No Solution"<<endl;
	else{
		//record the best road
		int k=n,num=0,v=m;
		while(k >= 0){
			if(choice[k][v] == 1){
				flag[k]=true;
				v-=w[k];
				num++;
			}else flag[k]=false;
			k--;
		}
		//output the solution
		for(int i=n;i>=1;i--){
			if(flag[i]==true){
				cout<<w[i];
				num--;
				if(num>0) cout<<" ";
			}
		}
	}
} 
