//PATA1011
/*idea:本题的目的是为了寻找最大赔率
 可以通过一个char类型的数组mp[3]表示0,1,2到W,T,L的映射关系 
 */ 
 
 #include <cstdio>
// char mp[3]={'W','T','L'};
 
 //对于输入的每一行，找到其中最大的那一个值 
 double getMax(double a, double b, double c){
	double max=-1;
	if(a>b){
		if(a>c){
			max=a;
		}else max = c;
	}else{
		if(b>c) max=b;
		else max=c;
	}
	return max;
 }
 
 char getResult(double a, double b, double c){
 		double max=-1;
	if(a>b){
		if(a>c){
			max=a;
		}else max = c;
	}else{
		if(b>c) max=b;
		else max=c;
	}
	if (max==a) return 'W';
	else if(max==b) return 'T';
	else return 'L';
 } 
 
 int main(){
 	double odd=1;	
 	double a,b,c;
 	char result[3];
 	for(int i=0;i<3;i++){
 		scanf("%lf%lf%lf",&a,&b,&c);
	 	odd*=getMax(a,b,c);
	 	result[i]=getResult(a,b,c);
	 }
	 double income;
	 income=(odd*0.65-1)*2;
	 printf("%c %c %c %.2f",result[0],result[1],result[2],income);
	return 0;
 } 
