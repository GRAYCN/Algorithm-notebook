//DFSѧϰ
#include<cstdio>
#include<iostream>
#define maxn 30
using namespace std;
//int n,V,maxValue=0;		//��Ʒ����n����������V������ֵmaxValue
//int w[maxn],c[maxn];		//w[i]Ϊÿ����Ʒ��������c[i]Ϊÿ����Ʒ�ļ�ֵ
//void DFS(int index, int sumW,int sumC) {
//	if(index == n) {
//		if(sumW <= V && sumC> maxValue) {
//			maxValue=sumC;
//		}
//		return;
//	}
//	DFS(index+1,sumW,sumC);		//��ѡ��index����Ʒ
//	DFS(index+1,sumW+w[index],sumC+c[index]);		//ѡ��index����Ʒ
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

