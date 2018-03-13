#include<iostream>  
#include<string>
#include<cctype>
  
using namespace std;  
  
//A1085
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
using namespace std;
#define maxn 100005
long long a[maxn];
int N,p; 


int binarySearch(int l, int r, long long num){
	int mid;
	while(l<r){
		mid=(l+r)/2;
		/*if(a[mid]>num){
			r=mid;
		}else{
			l=mid+1;
		}*/
		if(a[mid]<=num){
			l=mid+1;
		}else{
			r=mid;
		}
	}
	return l;
}

int main(){
	cin>>N>>p;
	for(int i=0;i<N;i++){
		cin>>a[i];
	}
	sort(a,a+N);
	int maxNum=0;
	for(int i=0;i<N;i++){
		int j=binarySearch(i+1,N,a[i]*p);
		//int j=upper_bound(a+i,a+N,(long long)a[i]*p)-a;
		maxNum=max(maxNum,j-i);
	}
	printf("%d",maxNum);
}
