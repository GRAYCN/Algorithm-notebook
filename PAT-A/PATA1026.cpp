//24' 
//PATA1026
#include<iostream>
#include<algorithm>
#include<vector>
#include <math.h>
#define maxn 10005
#define maxk 105
using namespace std;
struct player {
	int comeTime;
	int beginTime;
	int playingTime;
	bool isVIP;
	bool isServed;		//是否服务过 
} p;
struct table {
	bool isVIP;		//是否是VIP桌子
	int serveNum;	//该桌子的服务人数
	int endTime;
} t[maxk];			//1-k

vector<player> v;
int n,k,m;
int convert(int h,int m,int s) {
	return h*3600+m*60+s;
}
//查找min时间之前(包含)到达的队列中是否有尚未服务的VIP，有的话返回其下标，否则返回-1
int searchVIP(int min,int i) {
	while(i<v.size() && v[i].comeTime<=min) {
		if(v[i].isVIP==true && v[i].isServed==false) {
			return i;
		}
		i++;
	}
	return -1;
}
int cmpByComeTime(player a,player b) {
	return a.comeTime<b.comeTime;
}

int cmp2(player a,player b) {
	return a.beginTime<b.beginTime;
}

int main() {
	cin>>n;
	int h,m,s,P,tag;
	for(int i=0; i<n; i++) {
		scanf("%d:%d:%d %d %d",&h,&m,&s,&P,&tag);
		int comeTime = convert(h,m,s);
		p.comeTime=comeTime;
		p.playingTime= P<=120 ? P*60 : 7200;
		p.isVIP=tag;
		v.push_back(p);
	}
	cin>>k>>m;
	for(int i=0; i<m; i++) {
		int num;
		cin>>num;
		t[num].isVIP=1;
	}
	int startTime = convert(8,0,0);
	int endTime = convert(21,0,0);
	//对v中的人按照到来时间从小到大排序
	sort(v.begin(),v.end(),cmpByComeTime);
	//初始化endTime
	for(int i=1; i<=k; i++) {
		t[i].endTime=startTime;
	}
	//开始模拟
	//int cnt=0;
	for(int i=0; i<v.size(); i++) {
		//调试
		/*	cnt++;
			if(cnt==4){
				printf("1");
			}*/
		//找到空闲的最小桌子
		int index=-1,min=9999999;
		for(int j=1; j<=k; j++) {
			if(t[j].endTime<min) {
				min=t[j].endTime;
				index=j;
			}
		}
		if(min>=convert(21,0,0) || index==-1) break;		//关门之前也无法得到桌子，直接跳出
		if (v[i].isServed==true) {
			continue;			//i has been served
		}else{
			if(t[index].isVIP==true) {
				//min之前的队列中有没有还没服务的VIP，有的话直接服务该VIP.
				int VIP=searchVIP(min,i);
				if(VIP!=-1) {
					//服务VIP
					v[VIP].beginTime=min;			//开始时间恰好为 min
					v[VIP].isServed=true;
					t[index].endTime+=v[VIP].playingTime;
					i--;
					t[index].serveNum++;
					continue;
				}
				//如果这个vip不是当前遍历的i，那么i--，跳出
				//如果没有存在VIP，就按照常规步骤来
				else {
					//如果i早于index桌子结束到来，那么
					if(v[i].comeTime<t[index].endTime) {
						v[i].beginTime=min;
						v[i].isServed=true;
						t[index].endTime+=v[i].playingTime;
						t[index].serveNum++;
						//v[i].isServed=true;
					} else {	//如果i比index桌子结束要晚到
						v[i].beginTime=v[i].comeTime;
						v[i].isServed=true;
						t[index].endTime=v[i].beginTime + v[i].playingTime;
						t[index].serveNum++;
					}
				}
		 	}else{			//this table is not a VIP
		 						//如果i早于index桌子结束到来，那么
				if(v[i].comeTime<t[index].endTime) {
					v[i].beginTime=min;
					v[i].isServed=true;
					t[index].endTime+=v[i].playingTime;
					t[index].serveNum++;
					//v[i].isServed=true;
				} else {	//如果i比index桌子结束要晚到
					v[i].beginTime=v[i].comeTime;
					v[i].isServed=true;
					t[index].endTime=v[i].beginTime + v[i].playingTime;
					t[index].serveNum++;
				}	
		 	}	
		}
	}
	

	//输出结果
	sort(v.begin(),v.end(),cmp2);
	for(int i=0; i<v.size(); i++) {
		if(v[i].isServed==true) {
			int comeTime=v[i].comeTime;
			int beginTime=v[i].beginTime;
			printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",comeTime/3600,comeTime%3600/60,comeTime%60,beginTime/3600,beginTime%3600/60,beginTime%60,(beginTime-comeTime+30)/60);

		}
	}
	for (int i=1; i<=k; i++) {
		cout<<t[i].serveNum;
		if (i!=k) {
			cout<<" ";
		}

	}
}
