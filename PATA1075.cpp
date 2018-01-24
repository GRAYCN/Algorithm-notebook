#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct Man {
	int uid;
	int rank;
	int score[5];
} p[10005];
int s[5];
int n,k,m;

//�����ܷ�
int getSum(Man a) {
	int sum=0;
	for(int i=0; i<k; i++) {
		if(a.score[i]==-1)
			sum+=0;
		else sum+=a.score[i];
	}
	return sum;
}

int getAC(Man a) {
	int sum=0;
	for(int i=0; i<k; i++) {
		if(a.score[i]==s[i])
			sum++;
	}
	return sum;
}

int cmp(Man a,Man b) {
	if(getSum(a)!=getSum(b)) return getSum(a) >getSum(b);
	else if(getAC(a)!=getAC(b)) return getAC(a) > getAC(b);
	else return a.uid<b.uid;
}

int main() {
	scanf("%d%d%d",&n,&k,&m);
	for(int i=0; i<k; i++) {
		scanf("%d",&s[i]);
	}
	for(int i=1; i<=m; i++) {
		int uid,pid,score;
		scanf("%d%d%d",&uid,&pid,&score);			//�涨ĳһ����벻ͨ������û���ύʱ�÷�Ϊ0��ʵ�ʵ÷�Ϊ0���������-1
		p[uid].uid=uid;
		if(score == 0) score=-1;
		else if(score == -1) score =0;
		if(score>p[uid].score[pid])
			p[uid].score[pid]=score;			//��θ�����Ԫ�ظ���ֵ��
	}
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++){
		printf("%d %d\n",p[i].uid,getSum(p[i]));
	}
}
