// debug.cpp : ??????????????
//

//A1129
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
#include <set>
#include <vector>
#include <cstdio>
using namespace std;
#define maxn 50001
struct Item{
	int val;
	int freq;
	bool operator < (const Item b) const{
		if(freq!=b.freq){
			return freq>b.freq;
		}else return val<b.val;
	}
	Item(int v, int f){
		val=v;
		freq=f;
	}
}; 

int times[maxn];
int a[maxn];
int N,K;
int main(){
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	set<Item> rec;
	set<Item>::iterator it;
	for(int i=0;i<N-1;i++){
		it=rec.find(Item(a[i], times[a[i]]));
		if(it!=rec.end()){
			rec.erase(it);
		}
		times[a[i]]++;
		rec.insert(Item(a[i], times[a[i]]));
		int size=min(K, (int)rec.size());
		printf("%d:", a[i+1]);
        it = rec.begin();
       	for(int j = 0; j < size; ++j) {
           printf(" %d", it->val);
           it++;
    	}
        printf("\n");
		
	}
} 
