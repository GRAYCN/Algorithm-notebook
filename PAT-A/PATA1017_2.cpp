//PATA1017_2
//ACͨ�� 
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
	int beginTime;		//��ʼ�����ʱ��
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
		int comeTime = convert(hh,mm,ss);		//��Сʱת������
		c.serveTime=serveTime*60;
		c.comeTime=comeTime;
		v.push_back(c);
	}
	sort(v.begin(),v.end(),cmp);		//��������comeTime��С��������
	//һ��һ��ģ���û�����
	int cnt=0;
	double waitTime=0;
	for(int i=0;i<k;i++){
		endTime[i]=stTime;
	}
	for(int i=0; i<n; i++) {
		//��Ѱ����ʱ������Ĵ���
		int wIndex=-1, min=1<<30;
		for(int j=0; j<k; j++) {
			if(endTime[j]<min) {
				wIndex=j;
				min=endTime[j];
			}
		}
		//���ڷ���ʱ�䳤��60min�����⴦��
		if (v[i].serveTime>3600)
		{
			v[i].serveTime=3600;
		}

		//���˿�i����endTime[j]֮ǰ��������֮����
		//1.֮ǰ����: �ȴ�ʱ��ΪendTime[j]-comeTime
		int& comeTime=v[i].comeTime;
		if(v[i].comeTime<endTime[wIndex]) {
			//���´���j�Ľ���ʱ��
			v[i].beginTime=endTime[wIndex];
			//if(v[i].beginTime<enTime) {
			if(v[i].comeTime<enTime) {
				cnt++;
				waitTime+=v[i].beginTime-v[i].comeTime; 
			}
			endTime[wIndex]+=v[i].serveTime;
		}

		//2.֮���� :ֱ�ӽ��ܷ��񣬵ȴ�ʱ��Ϊ0
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
