//A1067
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
#include <cstdio>
using namespace std;
#define maxn 100010 

int pos[maxn];
int N,ans;

int main(){
	scanf("%d",&N);
	int left=N-1;
	for(int i=0;i<N;i++){
		int num;
		scanf("%d",&num);
		pos[num]=i;
		if(num==i && num!=0){
			left--;
		}
	}
	int k=1;
	while(left>0){
		if(pos[0]==0){
			while(k<N){
				if(pos[k]!=k){
					swap(pos[0],pos[k]);
					ans++;
					break;
				}
				k++;
			}
		}	
		while(pos[0]!=0){
			swap(pos[0],pos[pos[0]]);
			ans++;
			left--; 
		}
	}
	printf("%d",ans);
}
