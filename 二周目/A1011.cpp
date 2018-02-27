//A1011
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
#include <vector>
using namespace std;
#define maxn 100005
vector<int> result;
int N;
int leftMax[maxn],rightMin[maxn],a[maxn];
void init(){
	fill(leftMax,leftMax+N,-1);
	fill(rightMin,rightMin+N,1e9+1);
}

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	init();
	for(int i=1;i<N;i++){
		if(a[i-1]>leftMax[i-1]){
			leftMax[i]=a[i-1];
		}else{
			leftMax[i]=leftMax[i-1];
		}
	}	
	for(int i=N-2;i>=0;i--){
		if(a[i+1]<rightMin[i+1]){
			rightMin[i]=a[i+1];
		}else{
			rightMin[i]=rightMin[i+1];
		}
	}
	for(int i=0;i<N;i++){
		if(a[i]>leftMax[i] && a[i]<rightMin[i]){
			result.push_back(a[i]);
		}
	}
	printf("%d\n",result.size());
	for(int i=0;i<result.size();i++){
		printf("%d",result[i]);
		if(i!=result.size()-1){
			printf(" ");
		}
	}
	printf("\n");
}
