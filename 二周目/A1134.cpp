#include<cstdio>
#include<cstring>
#include<algorithm>
#include <string>
#include <vector> 
#define maxn 10005
using namespace std;
int N,M;
vector<int> v[maxn];
int hashTable[maxn];
int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(i);
		v[b].push_back(i);
	}
	int K;
	scanf("%d",&K);
	for(int i=0;i<K;i++){
		int num,query;
		scanf("%d",&num);
		fill(hashTable,hashTable+M,0);
		for(int j=0;j<num;j++){
			scanf("%d",&query);
			for(int k=0;k<v[query].size();k++){
				hashTable[v[query][k]]=1;
			}
		}
		bool flag=true;
		for(int j=0;j<M;j++){		//这里应该是M，误写成N 
			if(hashTable[j]==0){
				flag=false;
				break;
			}
		}
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
