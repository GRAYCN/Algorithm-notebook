//A1058
//��һ��Ī��������Ե��޷�ͨ�� ��int����Ϊlong long�󼴿���ͨ�� 
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
 
