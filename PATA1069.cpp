#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
int a[5];
//�Ӵ�С����
int cmp(int a,int b) {
	return a>b;
}

//��4λ����ת�������� 
void to_array(int n){
	for(int i=0;i<4;i++){
		a[i]=n%10;
		n/=10;
	}
}

int to_number(){
	int num=0;
	for(int i=0;i<4;i++){
		num=num*10+a[i];
	}
	return num;
}

int main() {
	int N,MAX,MIN;
	cin>>N;
	while(1){
		to_array(N);
		sort(a,a+4);
		MIN=to_number();
		sort(a,a+4,cmp);
		MAX=to_number();
		N=MAX-MIN;
		printf("%04d - %04d = %04d\n",MAX,MIN,N);
		if(N==6174 || N==0)
			break;	
	WW
	}

}
