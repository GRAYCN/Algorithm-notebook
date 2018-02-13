#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct Man {
	int uid;
	int rank;
	int score[8];
	bool output;
	int total;
	int perfect;
} p[10005];
int score[8];
int n,k,m;

int cmp(Man a,Man b) {
	if(a.output!=b.output) return a.output>b.output; 
	else if(a.total!=b.total) return a.total > b.total;
	else if(a.perfect!=b.perfect) return a.perfect > b.perfect;
	else return a.uid<b.uid;
}

void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			p[i].score[j]=-2;
		}
	}
}

void handle(){
	for(int i=1;i<=n;i++){
		//cal the sum 
		for(int j=1;j<=k;j++){
			if(p[i].score[j]>=0) p[i].total+=p[i].score[j];
			if(p[i].score[j]==score[j]) p[i].perfect++;
		}
	}	
}

int main() {
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1; i<=k; i++) {
		scanf("%d",&score[i]);
	}
	init();		//init the score to -2 to dinstinguish from [-1,100]
	for(int i=0; i<m; i++) {
		int uid,pid,score_obtained;
		scanf("%d%d%d",&uid,&pid,&score_obtained);//规定某一题编译不通过或者没有提交时得分为0，实际得分为0的情况记作-1
		p[uid].uid=uid;
		if(score_obtained>=0)
			p[uid].output=true;				//output
		if(score_obtained>p[uid].score[pid])
			p[uid].score[pid]=score_obtained;			//如何给数组元素赋初值？
	}
	handle();
	sort(p+1,p+n+1,cmp);	//sort
	int cnt=1;		
	p[1].rank=1;
	for(int i=2;i<=n;i++){		//rank
		cnt++;
		if(p[i].total<p[i-1].total){
			p[i].rank=cnt;
		}else p[i].rank=p[i-1].rank;
	}
	
	for(int i=1;i<=n;i++){
		if(p[i].output==false) continue;
		printf("%d %05d %d ",p[i].rank,p[i].uid,p[i].total);
		for(int j=1;j<=k;j++){
			if(p[i].score[j]>=0) cout<<p[i].score[j];
			else if(p[i].score[j]==-1) cout<<"0";
			else if(p[i].score[j]==-2) cout<<"-";
			if(j!=k) cout<<" ";
		}
		cout<<endl;
	}
}

