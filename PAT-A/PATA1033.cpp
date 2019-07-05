#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 510
#define INF 1000000000
struct station {
	double price, dis;
} st[maxn];

bool cmp(station a, station b) {
	return a.dis<b.dis;
}

int main() {
	int n;					//����վ����Ŀ�������յ㣩 
	double Cmax,D,Davg;		//������������������֮��ľ��룬ÿ�������ܵľ��� 
	cin>>Cmax>>D>>Davg>>n;
	for(int i=0; i<n; i++) {
		cin>>st[i].price>>st[i].dis;
	}
	//�涨�յ������⻯�ļ���վ
	st[n].price=0;
	st[n].dis=D;
	sort(st,st+n,cmp);
	//���������һ������վ���벻��0��˵���޷�ǰ��
	if(st[0].dis!=0) {
		printf("The maximum travel distance = 0.00\n");
	} else {
		int now=0;		//��ǰ�ļ���վ���

		double ans=0,nowTank=0,MAX=Cmax*Davg;
		while(now<n) {	//ÿһ��ѭ���ҳ���һ����Ҫ����ļ���վ
			//���û�е��ڵ�ǰ�ͼ۵ļ���վ����ѡ��۸���͵���һ��
			int k=-1;		//����ǰ���뷶Χ�ڵ�ǰ�ͼ���͵ļ���վ 
			double priceMin=INF;		//�ͼ���͵ļ���վ 
			for(int i=now+1; i<=n&&st[i].dis-st[now].dis<=MAX; i++) {
				if(st[i].price<priceMin) {
					priceMin=st[i].price;
					k=i;
				}
				if(priceMin<st[now].price) {
					break;
				}
			}
			if(k==-1)		//����״̬���Ҳ�������վ��������
				break;
			//����Ϊ���ҵ��ɵ���ļ���վ������ת�ƻ���
			double need=(st[k].dis-st[now].dis)/Davg;
			if(priceMin<st[now].price) {		//�������վk���ͼ۵��ڵ�ǰ�ͼ�
				//ֻ���㹻�������վk����
				if(nowTank<need) {	//�����ǰ��������need
					ans+=(need-nowTank)*st[now].price;
					nowTank=0;
				}else{
					nowTank-=need;
				}
			} else{		//�������վ���͸��ڵ�ǰ�ͼ� 
				ans+=(Cmax-nowTank)*st[now].price;
				nowTank=Cmax-need;
			}
			now=k;			//�������վk��������һ��ѭ�� 
		}
		if(now==n) {	//�ܵ����յ� 
			printf("%.2f\n",ans);
		} else {		//�޷������յ� 
			printf("The maximum travel distance = %.2f\n",st[now].dis+MAX);
		}
	}
}

