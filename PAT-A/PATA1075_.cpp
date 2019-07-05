//δ����� 
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct Man {
	int uid;
	int rank;
	int score[5];
	int tscore;
	bool flag;		//��¼�û��Ƿ�����ͨ��������ύ 
	int solve;		//��¼�û�AC����Ŀ 
} p[10005];
int s[6];
int n,k,m;

//��ʼ�� 
void init(){
	for(int i=1;i<=n;i++){
		p[i].uid=i;
		p[i].tscore=0;
		p[i].solve=0;
		p[i].flag=false;	//��ʼ��Ϊû���ܹ�ͨ��������ύ
		memset(p[i].score,-1,sizeof(p[i].score));		//���÷�ȫ����ʼ��Ϊ-1 
	}
}

//�����ܷ�
int getSum(Man a) {
	int sum=0;
	for(int i=1; i<=k; i++) {
		if(a.score[i]!=-1)
			sum+=a.score[i];
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
	if(a.tscore!=b.tscore) return a.tscore > b.tscore;
	else if(a.solve!=b.solve) return a.solve > b.solve;
	else return a.uid<b.uid;
}

int main() {
	init();		//�ȶԽṹ��������г�ʼ�� 
	scanf("%d%d%d", &n, &k, &m);
	for(int i=1; i<=k; i++) {
		scanf("%d",&s[i]);
	}
	for(int i=1; i<=m; i++) {
		int uid,pid,score;
		scanf("%d%d%d",&uid,&pid,&score);			//�涨ĳһ����벻ͨ������û���ύʱ�÷�Ϊ0��ʵ�ʵ÷�Ϊ0���������-1
//		����������� 
//		1.������ͨ��������ύ����flag��Ϊtrue
		if(score!=-1){
			p[uid].flag=true;
		}
// 		2.�ύ����δ��ͨ�����룬�����ǵ�һ���ύ����ô������÷���Ϊ0
		if(score == -1 && p[uid].score[pid] ==-1){
			p[uid].score[pid]=0;
		}
//		3.��һ��AC����AC��Ŀ+1
		if(p[uid].score[pid] ==s[pid]&& p[uid].score[pid] < s[pid]){
			p[uid].solve++;
		}
// 		4.�����ύ�÷ִ�����һ���ύ�����õ÷� 
		if(p[uid].score[pid] < s[pid]){
			p[uid].score[pid] = s[pid];
		}
	}
	//�����ܷ�
	for(int i=1;i<=n;i++){
		p[i].tscore=getSum(p[i]);
	} 
	sort(p+1,p+n+1,cmp);
	
	for(int i=1;i<=n;i++){
		printf("%d %d\n",p[i].uid,getSum(p[i]));
	}
}
