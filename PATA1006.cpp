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
	ans1.hh=24,ans1.mm=60,ans1.ss=60;				//�ѳ�ʼǩ��ʱ����Ϊ���
	ans2.hh=0, ans2.mm=0, ans2.ss=0;								//�ѳ�ʼǩ��ʱ����Ϊ��С
	for(int i=0; i<n; i++) {
		scanf("%s %d:%d:%d",temp.id,&temp.hh,&temp.mm,&temp.ss);
		if(great(temp,ans1)==false) ans1=temp;
		//����ǩ��ʱ��
		scanf("%d:%d:%d",&temp.hh,&temp.mm,&temp.ss);
		if(great(temp,ans2)==true) ans2=temp;
	}
	printf("%s %s\n",ans1.id,ans2.id);
}
