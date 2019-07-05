//和答案不太对应 

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int K = 111;
const int INF = 1000000000;
struct Customer{
	int comeTime,serveTime;		//客户到达的时间以及服务时长 
} newCustomer;					//newCustomer临时存放新客户的信息 
vector<Customer> custom;

int convert(int h,int m,int s){
	return 3600*h+60*m+s;
} 

int cmp(Customer a, Customer b){
	return a.comeTime<b.comeTime;
}

int endTime[K];		//endTime记录i号窗口的当前服务时间 

int main(){
	int c,w,totTime=0; 
	int stTime=convert(8,0,0);
	int enTime=convert(17,0,0);
	cin>>c>>w;
	for(int i=0;i<w;i++) endTime[i]=stTime;		//没有客户，将窗口的服务截止时间初始化为stTime
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
	sort(custom.begin(),custom.end(),cmp);		//按照到达时间从先到后排列
	for(int i=0;i<custom.size();i++){
		int idx=-1,minEndTime=INF;
		for(int j=0;j<w;j++){
			if(endTime[j]<minEndTime){
				minEndTime=endTime[i];
				idx=j;
			}
		}
		//idx为最早 结束服务的窗口编号，将客户custom[i]分配到该窗口
		if(endTime[idx] <= custom[i].comeTime){
			//如果客户在窗口结束服务之后才到来，那么就没有等待时间
			endTime[idx]=custom[i].comeTime+custom[i].serveTime; 
		} else{
			totTime+=(endTime[idx]-custom[i].comeTime);
			endTime[idx]+=custom[i].serveTime;
		}
	} 
	if(custom.size()==0) printf("0.0");
	else printf("%.1f",totTime/60.0/custom.size()); 
} 
