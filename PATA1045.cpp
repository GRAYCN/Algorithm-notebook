#include<iostream>

using namespace std;
int color[210],favourite[210],stripe[10005],dp[10005],mp[210];
int N,M,L;

void findN(int j){
	for(int i=0;i<M;i++){
		if(favourite[i] == j){
			//return i;
			mp[j]=i; 
			return;
		}
	}
	//return -1;
	mp[j]=-1;
	return;
}

void init(){
	for(int i=1;i<=N;i++){
		findN(i);
	}
}

int main() {
	cin>>N>>M;
	for(int i=0; i<M; i++) {
		cin>>favourite[i];
	}
	cin>>L;
	for(int i=0; i<L; i++) {
		cin>>stripe[i];
	}
	for(int i=0; i<L; i++) {
		dp[i]=1;
	}

	init();

	for(int i=1; i<L; i++) {
		for(int j=0; j<i; j++) {
			if(mp[stripe[i]]!=-1 && mp[stripe[j]]!=-1 &&mp[stripe[i]]>=mp[stripe[j]] && dp[j]+1>dp[i]) {	//如果i的位次在favourite中比靠后并且 dp[j]+1>dp[i]
				dp[i]=dp[j]+1;
			}
		}
	}
	int max=0;
	for(int i=1;i<L;i++){
		if(dp[i]>dp[max]){
			max=i;
		}
	}
	cout<<dp[max];
}
