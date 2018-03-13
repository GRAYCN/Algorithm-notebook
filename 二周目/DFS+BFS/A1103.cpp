#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
#include <vector>
using namespace std;

int N,K,P;
vector<int> v,tempResult,result;
int sum=-1;

int cifang(int n,int P){
	int result=1;
	for(int i=1;i<=P;i++){
		result*=n;
	}
	return result;
}
int flag=false;
void DFS(int nowK, int num ,int nowSum,int FacSum){
	if(nowSum==N && nowK==K){
		flag=true;
		//output
		if (FacSum>sum){
			sum=FacSum;
			result=v;
		}
	}
	if(nowSum>=N || nowK>K){
		return;
	}
	//v.push_back(num);
	for(int i=num;i>=1;i--){
		v.push_back(i);
		DFS(nowK+1,i,nowSum+cifang(i,P),FacSum+i);
		v.pop_back();
	}
	//v.pop_back();
	
} 

int main(){
	cin>>N>>K>>P;
	DFS(0,(int)sqrt((double)N),0,0);
	if (flag)
	{
		printf("%d = ",N);
		for(int i=0;i<result.size();i++){
			printf("%d^%d",result[i],P);
			if(i!=result.size()-1){
				printf(" + ");
			}
		}
	}
	else{
		printf("Impossible");
	}

	
}

