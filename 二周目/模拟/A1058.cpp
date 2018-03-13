//A1058
//有一处莫名其妙测试点无法通过 将int更改为long long后即可以通过 
#include<iostream>
#include<cstring>
#include<algorithm>
#include <string>
#include <cmath>
using namespace std;

long long G1,G2,S1,S2,K1,K2,K3;
long long Galleon=17*29,Sickle=29;

int main(){
	scanf("%d.%d.%d",&G1,&S1,&K1);
	scanf("%d.%d.%d",&G2,&S2,&K2);
	K1=G1*Galleon+S1*Sickle+K1;
	K2=G2*Galleon+S2*Sickle+K2;
	K3=K1+K2;
	printf("%lld.%lld.%lld",K3/Galleon,K3%Galleon/Sickle,K3%Sickle);
	printf("\n");
}
 
