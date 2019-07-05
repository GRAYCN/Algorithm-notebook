//PATA1108
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
char str[1024];

double parse(const char *str){		//why use const char?
	bool minus=false;	//Is there any minus symbol?	
	bool dot=false;		// is there any dot symbol?
	int nDot=0;			// the number of dot
	int sum=0;			// the sum of the number
	for(int i=0;str[i];i++){
		if(!minus && str[0]=='-'){
			minus=true;
		}else if(!dot && str[i]=='.' && (i!=0)){
			dot=true;
		}else if(str[i]>='0' && str[i]<='9'){
			sum*=10;
			sum+=str[i]-'0';
			if(dot){
				nDot++;
			}
		}else{
			return 1001;
		}
	}
	sum *= (minus ? -1:1);
	if(nDot <=2){
		double times[3]={1,10,100};
		double res= sum/times[nDot];
		if(res>=-1000 && res<=1000)
			return res;
	}
	return 1001;
}

int main(){
	int n;
	scanf("%d",&n);
	int nValid=0;
	double sum=0;
	for(int i=0;i<n;++i){
		scanf("%s",str);
		double res = parse(str);
		if(res == 1001){
       		printf("ERROR: %s is not a legal number\n", str);
		}else{
			sum += res;
			nValid++;
		}
	}
	//handle the output
    if (nValid == 0) {
        printf("The average of 0 numbers is Undefined\n");
    } else if (nValid == 1){ // ?!
        printf("The average of %d number is %.2lf\n", nValid, sum/nValid);
    } else {
        printf("The average of %d numbers is %.2lf\n", nValid, sum/nValid);
    }
}
