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
	bool isServed;		//�Ƿ����� 
} p;
struct table {
	bool isVIP;		//�Ƿ���VIP����
	int serveNum;	//�����ӵķ�������
	int endTime;
} t[maxk];			//1-k

vector<player> v;
int n,k,m;
int convert(int h,int m,int s) {
	return h*3600+m*60+s;
}
//����minʱ��֮ǰ(����)����Ķ������Ƿ�����δ�����VIP���еĻ��������±꣬���򷵻�-1
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
	//��v�е��˰��յ���ʱ���С��������
	sort(v.begin(),v.end(),cmpByComeTime);
	//��ʼ��endTime
	for(int i=1; i<=k; i++) {
		t[i].endTime=startTime;
	}
	//��ʼģ��
	//int cnt=0;
	for(int i=0; i<v.size(); i++) {
		//����
		/*	cnt++;
			if(cnt==4){
				printf("1");
			}*/
		//�ҵ����е���С����
		int index=-1,min=9999999;
		for(int j=1; j<=k; j++) {
			if(t[j].endTime<min) {
				min=t[j].endTime;
				index=j;
			}
		}
		if(min>=convert(21,0,0) || index==-1) break;		//����֮ǰҲ�޷��õ����ӣ�ֱ������
		if (v[i].isServed==true) {
			continue;			//i has been served
		}else{
			if(t[index].isVIP==true) {
				//min֮ǰ�Ķ�������û�л�û�����VIP���еĻ�ֱ�ӷ����VIP.
				int VIP=searchVIP(min,i);
				if(VIP!=-1) {
					//����VIP
					v[VIP].beginTime=min;			//��ʼʱ��ǡ��Ϊ min
					v[VIP].isServed=true;
					t[index].endTime+=v[VIP].playingTime;
					i--;
					t[index].serveNum++;
					continue;
				}
				//������vip���ǵ�ǰ������i����ôi--������
				//���û�д���VIP���Ͱ��ճ��沽����
				else {
					//���i����index���ӽ�����������ô
					if(v[i].comeTime<t[index].endTime) {
						v[i].beginTime=min;
						v[i].isServed=true;
						t[index].endTime+=v[i].playingTime;
						t[index].serveNum++;
						//v[i].isServed=true;
					} else {	//���i��index���ӽ���Ҫ��
						v[i].beginTime=v[i].comeTime;
						v[i].isServed=true;
						t[index].endTime=v[i].beginTime + v[i].playingTime;
						t[index].serveNum++;
					}
				}
		 	}else{			//this table is not a VIP
		 						//���i����index���ӽ�����������ô
				if(v[i].comeTime<t[index].endTime) {
					v[i].beginTime=min;
					v[i].isServed=true;
					t[index].endTime+=v[i].playingTime;
					t[index].serveNum++;
					//v[i].isServed=true;
				} else {	//���i��index���ӽ���Ҫ��
					v[i].beginTime=v[i].comeTime;
					v[i].isServed=true;
					t[index].endTime=v[i].beginTime + v[i].playingTime;
					t[index].serveNum++;
				}	
		 	}	
		}
	}
	

	//������
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
