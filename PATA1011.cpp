//PATA1011
/*idea:�����Ŀ����Ϊ��Ѱ���������
 ����ͨ��һ��char���͵�����mp[3]��ʾ0,1,2��W,T,L��ӳ���ϵ 
 */ 
 
 #include <cstdio>
// char mp[3]={'W','T','L'};
 
 //���������ÿһ�У��ҵ�����������һ��ֵ 
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
