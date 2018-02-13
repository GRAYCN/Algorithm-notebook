//PATA1017_2
//AC通过 
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#define maxn 10005
#define maxk 105
using namespace std;
struct customer {
	int comeTime;
	int serveTime;
	int beginTime;		//开始服务的时间
} c;
int endTime[maxk];
vector<customer> v;
int convert(int h,int m,int s) {
	return h*3600+m*60+s;
}

int cmp(customer a, customer b) {
	return a.comeTime<b.comeTime;
}


int n,k;
int main() {
	cin>>n>>k;
	int stTime=convert(8,0,0);
	int enTime=convert(17,0,0);
	int hh,mm,ss;
	for(int i=0; i<n; i++) {
		int serveTime;
		scanf("%d:%d:%d %d",&hh,&mm,&ss,&serveTime);
		int comeTime = convert(hh,mm,ss);		//将小时转换成秒
		c.serveTime=serveTime*60;
		c.comeTime=comeTime;
		v.push_back(c);
	}
	sort(v.begin(),v.end(),cmp);		//按照先来comeTime从小到大排序
	//一个一个模拟用户到来
	int cnt=0;
	double waitTime=0;
	for(int i=0;i<k;i++){
		endTime[i]=stTime;
	}
	for(int i=0; i<n; i++) {
		//找寻结束时间最早的窗口
		int wIndex=-1, min=1<<30;
		for(int j=0; j<k; j++) {
			if(endTime[j]<min) {
				wIndex=j;
				min=endTime[j];
			}
		}
		//对于服务时间长于60min的特殊处理
		if (v[i].serveTime>3600)
		{
			v[i].serveTime=3600;
		}

		//看顾客i是在endTime[j]之前到来还是之后到来
		//1.之前到来: 等待时间为endTime[j]-comeTime
		int& comeTime=v[i].comeTime;
		if(v[i].comeTime<endTime[wIndex]) {
			//更新窗口j的结束时间
			v[i].beginTime=endTime[wIndex];
			//if(v[i].beginTime<enTime) {
			if(v[i].comeTime<enTime) {
				cnt++;
				waitTime+=v[i].beginTime-v[i].comeTime; 
			}
			endTime[wIndex]+=v[i].serveTime;
		}

		//2.之后到来 :直接接受服务，等待时间为0
		else {
			v[i].beginTime=v[i].comeTime;
			//if(v[i].beginTime<convert(17,0,0)) {
			if(v[i].comeTime<enTime) {
				cnt++;
			}
			endTime[wIndex]=v[i].beginTime+v[i].serveTime;
		}
	}
	printf("%.1f",waitTime/cnt/60);
}
