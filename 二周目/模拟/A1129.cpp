// debug.cpp : ??????????????
//

//A1129
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
#include <map>
#include <vector>
#include <cstdio>
using namespace std;
#define maxn 50001
struct Node{
	int index;
	int cnt;
	Node(i,c){
		index=i;
		cnt=c;
	}
};

vector<Node> v;
vector<int> a;
int N,K;
int times[maxn];

int cmp(Node a, Node b){
	if(a.cnt!=b.cnt) return a.cnt>b.cnt;
	else return a.index<b.index;
}

int main(){
	scanf("%d%d",&N,&K);
	v1.resize(N+1);
	a.resize(N);
	vector<Node> iterator::it;
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<N-1;i++){
		times[a[i]]++;
		
		v1[ a[i] ].index=a[i];
		v1[ a[i] ].cnt++;
		v2=v1;
		sort(v2.begin()+1,v2.begin()+N+1,cmp);
		printf("%d:",a[i+1]);
		int j=1;
		while(j<=K && v2[j].cnt>0){
			printf(" %d",v2[j].index);
			j++;
		}
		printf("\n");
	}
} 
