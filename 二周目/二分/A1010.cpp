#include<iostream>  
#include<string>
#include<cctype>
  
using namespace std;  
  
//A1010
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
typedef long long LL;
using namespace std;
LL Map[256];
LL inf=(1LL<<63)-1;

void init(){
	for(int i='0';i<='9';i++){
		Map[i]=i-'0';
	}
	for(int i='a';i<='z';i++){
		Map[i]=i-'a'+10;
	}
}

LL convert(char a[], LL radix, LL t){
	LL ans=0;
	int len=strlen(a);
	for(int i=0;i<len;i++){
		ans=ans*radix+Map[a[i]];
		if(ans<0) return -1;
	}
	return ans;
}

int cmp(char N2[], LL radix, LL t){
	int len=strlen(N2);
	LL num=convert(N2,radix, t);
	if(num<0) return 1;
	if(t>num) return -1;
	else if(t==num) return 0;
	else return 1;
}

LL binarySearch(char N2[], LL left, LL right, LL t){
	LL mid;
	while(left<=right){
		mid=(left+right)/2;
		int flag=cmp(N2,mid,t);
		if(flag==0) return mid;
		else if(flag==-1) left=mid+1;
		else right=mid-1;
	}
	return -1;
} 

int findLargestDigit(char N2[]){
	int ans=-1, len=strlen(N2);
	for(int i=0;i<len;i++){
		if(Map[N2[i]]>ans){
			ans=Map[N2[i]];
		}
	}
	return ans+1;
}

char N1[20], N2[20], temp[20];
int tag, radix;
int main(){
	init();
	cin>>N1>>N2>>tag>>radix;
	if(tag==2){
		strcpy(temp,N1);
		strcpy(N1,N2);
		strcpy(N2,temp);
	}
	LL t = convert(N1,radix,inf);
	LL low = findLargestDigit(N2);
	LL high=max(low,t)+1;
	LL ans = binarySearch(N2,low,high,t);
	if(ans==-1) cout<<"Impossible"<<endl;
	else cout<<ans<<endl;
}


