//PATA1011
/*idea:�����Ŀ����Ϊ��Ѱ���������
 ����ͨ��һ��char���͵�����mp[3]��ʾ0,1,2��W,T,L��ӳ���ϵ 
 */ 
 
 #include <cstdio>
 #include <algorithm> 
 using namespace std;
// char mp[3]={'W','T','L'};
 
 //���������ÿһ�У��ҵ�����������һ��ֵ 
 double getMax(double a, double b, double c){
	double max1=-1;
	max1=max(a,max(b,c));
	return max1;
 }
 
 char getResult(double a, double b, double c){
 		double max1=-1;
	max1=max(a,max(b,c));
	if (max1==a) return 'W';
	else if(max1==b) return 'T';
	else return 'L';
 } ����5896QWE 
 
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
