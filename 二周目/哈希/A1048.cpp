#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<string>
using namespace std;
#define maxn 1005
int hashTable[maxn];

int main() {
	int n,m,a;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		hashTable[a]++;
	}
	for(int i=1;i<m;i++){
		if(hashTable[i] && hashTable[m-i]){
			if(i==m-i && hashTable[i]<=1){
				continue;
			}
			printf("%d %d\n",i,m-i);
			return 0;
		}
	}
	printf("No Solution\n");
	return 0;
}
