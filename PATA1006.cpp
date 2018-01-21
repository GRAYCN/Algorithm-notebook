//PATA1006
#include <cstdio>

struct pNode {
	char id[20];
	int hh,mm,ss;
} temp, ans1, ans2;

bool great(pNode p1, pNode p2) {
	if(p1.hh!=p2.hh) return p1.hh>p2.hh;
	else if(p1.mm!=p2.mm) return p1.mm>p2.mm;
	return p1.ss>p2.ss;
}

int main() {
	int n;
	scanf("%d",&n);
	ans1.hh=24,ans1.mm=60,ans1.ss=60;				//把初始签到时间设为最大
	ans2.hh=0, ans2.mm=0, ans2.ss=0;								//把初始签离时间设为最小
	for(int i=0; i<n; i++) {
		scanf("%s %d:%d:%d",temp.id,&temp.hh,&temp.mm,&temp.ss);
		if(great(temp,ans1)==false) ans1=temp;
		//读入签出时间
		scanf("%d:%d:%d",&temp.hh,&temp.mm,&temp.ss);
		if(great(temp,ans2)==true) ans2=temp;
	}
	printf("%s %s\n",ans1.id,ans2.id);
}
