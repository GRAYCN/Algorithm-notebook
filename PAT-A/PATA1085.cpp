//
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 100005
int n;
long long p;
long long a[maxn];

int main(){
	cin>>n>>p;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int ans=1;
	for(int i=0;i<n;i++){
		int j = upper_bound(a+i+1,a+n,a[i]*p)-a;
		ans=max(ans,j-i);
	}
	cout<<ans;
} 
