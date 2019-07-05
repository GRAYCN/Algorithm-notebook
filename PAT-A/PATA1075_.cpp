//未完待续 
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct Man {
	int uid;
	int rank;
	int score[5];
	int tscore;
	bool flag;		//记录用户是否有能通过编译的提交 
	int solve;		//记录用户AC的题目 
} p[10005];
int s[6];
int n,k,m;

//初始化 
void init(){
	for(int i=1;i<=n;i++){
		p[i].uid=i;
		p[i].tscore=0;
		p[i].solve=0;
		p[i].flag=false;	//初始化为没有能够通过编译的提交
		memset(p[i].score,-1,sizeof(p[i].score));		//将得分全部初始化为-1 
	}
}

//计算总分
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
	init();		//先对结构体数组进行初始化 
	scanf("%d%d%d", &n, &k, &m);
	for(int i=1; i<=k; i++) {
		scanf("%d",&s[i]);
	}
	for(int i=1; i<=m; i++) {
		int uid,pid,score;
		scanf("%d%d%d",&uid,&pid,&score);			//规定某一题编译不通过或者没有提交时得分为0，实际得分为0的情况记作-1
//		存在四种情况 
//		1.存在能通过编译的提交，将flag置为true
		if(score!=-1){
			p[uid].flag=true;
		}
// 		2.提交内容未能通过编译，并且是第一次提交，那么将改题得分置为0
		if(score == -1 && p[uid].score[pid] ==-1){
			p[uid].score[pid]=0;
		}
//		3.第一次AC，将AC数目+1
		if(p[uid].score[pid] ==s[pid]&& p[uid].score[pid] < s[pid]){
			p[uid].solve++;
		}
// 		4.本次提交得分大于上一次提交，重置得分 
		if(p[uid].score[pid] < s[pid]){
			p[uid].score[pid] = s[pid];
		}
	}
	//计算总分
	for(int i=1;i<=n;i++){
		p[i].tscore=getSum(p[i]);
	} 
	sort(p+1,p+n+1,cmp);
	
	for(int i=1;i<=n;i++){
		printf("%d %d\n",p[i].uid,getSum(p[i]));
	}
}
