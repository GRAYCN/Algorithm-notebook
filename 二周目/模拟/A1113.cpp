#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
#include <map>
using namespace std;
#define maxn 100005
int a[maxn];
int diffN,diffS;
int S1,S2;

int main(){
	int N;
	cin>>N;
	diffN=N%2;
	for(int i=0;i<N;i++){
		cin>>a[i];
	}
	sort(a,a+N);
	for(int i=0;i<N/2;i++){
		S1+=a[i];
	}
	
	for(int i=N/2;i<N;i++){
		S2+=a[i];
	}
	diffS=S2-S1;
	printf("%d %d",diffN,diffS);
}
