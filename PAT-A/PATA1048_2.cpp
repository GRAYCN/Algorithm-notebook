//Î´Íê´ıĞø 
#include <iostream>
#include <algorithm>
using namespace std;

int a[100010];

int main(){
	int i,n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		int pos = upper_bound(a,a+n,m-a[i])-a;
		if((pos-1!=i)&& a[i]+a[pos-1]==m){
			printf("%d %d\n",a[i],a[pos-1]);
			return 0;
		} 
	}
	printf("No Solution\n");
}
