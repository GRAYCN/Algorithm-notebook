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
	int n;					//加油站的数目（不算终点） 
	double Cmax,D,Davg;		//油箱的最大容量，城市之间的距离，每升油能跑的距离 
	cin>>Cmax>>D>>Davg>>n;
	for(int i=0; i<n; i++) {
		cin>>st[i].price>>st[i].dis;
	}
	//规定终点是特殊化的加油站
	st[n].price=0;
	st[n].dis=D;
	sort(st,st+n,cmp);
	//如果排序后第一个加油站距离不是0，说明无法前进
	if(st[0].dis!=0) {
		printf("The maximum travel distance = 0.00\n");
	} else {
		int now=0;		//当前的加油站编号

		double ans=0,nowTank=0,MAX=Cmax*Davg;
		while(now<n) {	//每一次循环找出下一个需要到达的加油站
			//如果没有低于当前油价的加油站，则选择价格最低的那一个
			int k=-1;		//代表当前距离范围内当前油价最低的加油站 
			double priceMin=INF;		//油价最低的加油站 
			for(int i=now+1; i<=n&&st[i].dis-st[now].dis<=MAX; i++) {
				if(st[i].price<priceMin) {
					priceMin=st[i].price;
					k=i;
				}
				if(priceMin<st[now].price) {
					break;
				}
			}
			if(k==-1)		//满油状态下找不到加油站，则跳出
				break;
			//下面为能找到可到达的加油站，计算转移花费
			double need=(st[k].dis-st[now].dis)/Davg;
			if(priceMin<st[now].price) {		//如果加油站k的油价低于当前油价
				//只买足够到达加油站k的油
				if(nowTank<need) {	//如果当前油量不足need
					ans+=(need-nowTank)*st[now].price;
					nowTank=0;
				}else{
					nowTank-=need;
				}
			} else{		//如果加油站的油高于当前油价 
				ans+=(Cmax-nowTank)*st[now].price;
				nowTank=Cmax-need;
			}
			now=k;			//到达加油站k，进入下一层循环 
		}
		if(now==n) {	//能到达终点 
			printf("%.2f\n",ans);
		} else {		//无法到达终点 
			printf("The maximum travel distance = %.2f\n",st[now].dis+MAX);
		}
	}
}

