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
		if(a[i]>n-i)//n-iΪ������i�������ж�������ϵ�i�챾���������ֻҪa[i]���������������ô�����ÿһ�춼���������������ôn-i���Ǵ��ˡ�</span>  
		{  
			ans=n-i;  
			break;  
		}  
		cout<<ans<<endl;  
		return 0;  
}  
