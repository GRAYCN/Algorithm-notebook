//DFS学习
#include<cstdio>
#include<iostream>
#define maxn 30
using namespace std;
//int n,V,maxValue=0;		//物品件数n，背包容量V，最大价值maxValue
//int w[maxn],c[maxn];		//w[i]为每件物品的重量，c[i]为每件物品的价值
//void DFS(int index, int sumW,int sumC) {
//	if(index == n) {
//		if(sumW <= V && sumC> maxValue) {
//			maxValue=sumC;
//		}
//		return;
//	}
//	DFS(index+1,sumW,sumC);		//不选第index件物品
//	DFS(index+1,sumW+w[index],sumC+c[index]);		//选第index件物品
//}
//int main() {
//	cin>>n>>V;
//	for(int i=0;i<n;i++){
//		cin>>w[i];
//	} 
//	for(int i=0;i<n;i++){
//		cin>>c[i];
//	} 
//	DFS(0,0,0);
//	cout<<maxValue<<endl; 
//}

int n,V,maxValue=0;
int w[maxn],c[maxn];
void DFS(int index, int sumW, int sumC){
	if(index==n){		//dead hutong
		if(sumW<=V && sumC>maxValue){
			maxValue=sumC;
		}
		return;
	}
	//crossroad
	DFS(index+1,sumW,sumC);
	DFS(index+1,sumW+w[index],sumC+c[index]);
}

void DFS(int index, int sumW, int sumC){
	if(index==n){		//dead hutong
//		if(sumW<=V && sumC>maxValue){
//			maxValue=sumC;
//		}
		return;
	}
	//crossroad
	DFS(index+1,sumW,sumC);
	if(sumW+w[index]<=V){
		if(sumC+c[index]>maxValue){
			maxValue=sumC+c[index];
		}
		DFS(index+1,sumW+w[index],sumC+c[index]);
	}
	
} 

