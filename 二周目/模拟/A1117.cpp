#include <iostream>  
#include<algorithm>  
#include<stdio.h>  
using namespace std;
#define maxn 10005
int a[maxn]; 
int main()  
{  
	int n,ans=0;  
	cin>>n;  
 
	for(int i=0; i<n; i++)  
		scanf("%d",&a[i]);  
	sort(a,a+n);  
	for(int i=0; i<n; i++)  
		if(a[i]>n-i)//n-i为排序后第i个后面有多少天加上第i天本身的天数，只要a[i]大于这个天数，那么后面的每一天都大于这个天数，那么n-i就是答案了。</span>  
		{  
			ans=n-i;  
			break;  
		}  
		cout<<ans<<endl;  
		return 0;  
}  
