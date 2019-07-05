//PATA1010
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
LL map[256];
LL inf = (1LL<<63)-1;		//long long ���ֵ

//�������ѧϰ
void init(){
	for(char c='0';c<='9';c++){
		map[c]=c-'0';		//��'0'-'9'ӳ��Ϊ0-9 
	}
	for(char c='a';c<='z';c++){
		map[c]=c-'a'+10;	
	} 
}

LL convert(char a[], LL radix, LL t){
	LL ans = 0;
	int len = strlen(a);
	for(int i=0;i<len;i++){
		ans=ans*radix+map[a[i]];		//����ת�� 
		if(ans<0 || ans>t) return -1;	//����򳬹�N1��ʮ���� 
	}
	return ans;
}

int cmp(char N2[],LL radix, LL t){	//N2��ʮ������t�Ƚ� 
	int len = strlen(N2);
	LL num = convert(N2,radix,t);
	if(num<0) return 1;
	if(t>num) return -1;
	else if(t == num) return 0;
	else return 1;
}

LL binarySearch(char N2[],LL left,LL right, LL t){
	LL mid;
	while(left<=right){
		mid=(left+right)/2;
		int flag=cmp(N2,mid,t);	//�ж�N2ת��Ϊʮ���ƺ���t�Ƚ� 
		if(flag==0) return mid;
		else if(flag==-1) left=mid+1;
		else right=mid-1; 
	}
	return -1;
}  

int findLargestDigit(char N2[])		//��������λ
{
	int ans=-1,len= strlen(N2);
	for(int i=0;i<len;i++){
		if(map[N2[i]]>ans){
			ans = map[N2[i]];
		}
	}
	return ans+1;
} 

char N1[20],N2[20],temp[20];
int tag,radix;
int main(){
	init();
	scanf("%s %s %d %d",N1,N2,&tag,&radix);
	if(tag==2){
		strcpy(temp,N1);
		strcpy(N1,N2);
		strcpy(N2,temp);
	}
	LL t = convert(N1,radix,inf);		//��N1��radix����ת��ʮ����
	LL low = findLargestDigit(N2);
	LL high= max(low,t)+1;
	LL ans = binarySearch(N2,low,high,t);
	if(ans == -1) cout<<"Impossible\n";
	else cout<<ans; 
}
