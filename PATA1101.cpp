// bomb segment fault and time-limit exceeded
// it tells us that when the scale of data reach 10^5,we must not
// use the algorithm with a time complexity of N^2
//PATA1101
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N;
#define maxn 100010
int a[maxn];
bool wrong[maxn];
vector<int> result;
void init(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(j<i && a[j]>a[i]){
				wrong[a[i]]=true;
				break;
			}	
			if(j>i && a[j]<a[i]){
				wrong[a[i]]=true;
				break;			
			}
		}
	}
}
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	init();
	for(int i=0;i<N;i++){
		if(!wrong[a[i]]){
			result.push_back(a[i]);
		}
	}
	sort(result.begin(),result.end());
	printf("%d\n",result.size());
	for(int i=0;i<result.size();i++){
		printf("%d",result[i]);
		if(i!=result.size()-1){
			printf(" ");
		}
	}
}
