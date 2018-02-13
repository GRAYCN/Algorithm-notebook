//PATA1104_2
#include <iostream>

using namespace std;
double sum;
int main(){
	int N;
	double in;
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>in;
		sum+=in*i*(N-i+1);	
	}
	printf("%.2f\n",sum);
}
