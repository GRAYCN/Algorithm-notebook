//�ʹ𰸲�̫��Ӧ 

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int K = 111;
const int INF = 1000000000;
struct Customer{
	int comeTime,serveTime;		//�ͻ������ʱ���Լ�����ʱ�� 
} newCustomer;					//newCustomer��ʱ����¿ͻ�����Ϣ 
vector<Customer> custom;

int convert(int h,int m,int s){
	return 3600*h+60*m+s;
} 

int cmp(Customer a, Customer b){
	return a.comeTime<b.comeTime;
}

int endTime[K];		//endTime��¼i�Ŵ��ڵĵ�ǰ����ʱ�� 

int main(){
	int c,w,totTime=0; 
	int stTime=convert(8,0,0);
	int enTime=convert(17,0,0);
	cin>>c>>w;
	for(int i=0;i<w;i++) endTime[i]=stTime;		//û�пͻ��������ڵķ����ֹʱ���ʼ��ΪstTime
	for(int i=0;i<c;i++){
		int h,m,s,serveTime;
		scanf("%d:%d:%d %d",&h,&m,&s,&serveTime);
		//		cin>>h>>m>>s>>serveTime;
		int comeTime=convert(h,m,s);
		if(comeTime>enTime){
			continue;
		}
		newCustomer.comeTime=comeTime;
		newCustomer.serveTime=serveTime<60?serveTime*60:3600;
		custom.push_back(newCustomer);
	}
	sort(custom.begin(),custom.end(),cmp);		//���յ���ʱ����ȵ�������
	for(int i=0;i<custom.size();i++){
		int idx=-1,minEndTime=INF;
		for(int j=0;j<w;j++){
			if(endTime[j]<minEndTime){
				minEndTime=endTime[i];
				idx=j;
			}
		}
		//idxΪ���� ��������Ĵ��ڱ�ţ����ͻ�custom[i]���䵽�ô���
		if(endTime[idx] <= custom[i].comeTime){
			//����ͻ��ڴ��ڽ�������֮��ŵ�������ô��û�еȴ�ʱ��
			endTime[idx]=custom[i].comeTime+custom[i].serveTime; 
		} else{
			totTime+=(endTime[idx]-custom[i].comeTime);
			endTime[idx]+=custom[i].serveTime;
		}
	} 
	if(custom.size()==0) printf("0.0");
	else printf("%.1f",totTime/60.0/custom.size()); 
} 
