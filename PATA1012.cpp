#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct Student {
	int id;
	int grade[4];
} stu[2010];

char course[4] = {'A','C','M','E'};
int Rank[1000000][4]= {0};
int now;		//在cmp中使用，表示当前按照now号分数递减排序

bool cmp(Student a,Student b) {
	return a.grade[now] > b.grade[now];
}

int main() {
	int n,m;
	cin>>n>>m;
	for(int i=0; i<n; i++) {
		cin>>stu[i].id>>stu[i].grade[1]>>stu[i].grade[2]>>stu[i].grade[3];
		stu[i].grade[0]=stu[i].grade[1]+stu[i].grade[2]+stu[i].grade[3];
	}
	for(now=0; now<4; now++) {
		sort(stu,stu+n,cmp);
		Rank[stu[0].id][now]=1;
		for(int i=1; i<n; i++) {
			if(stu[i].grade[now]== stu[i-1].grade[now])
				Rank[stu[i].id][now]=Rank[stu[i-1].id][now];
			else Rank[stu[i].id][now]=i+1;
		}
	}
	int query;		//查询考生的id
	for(int i=0; i<m; i++) {
		cin>>query;
		if(Rank[query][0]==0)
			cout<<"N/A"<<endl;
		else {
			int k=0;
			for(int j=0; j<4; j++) {
				if(Rank[query][j]<Rank[query][k])
					k=j;
			}
			cout<<Rank[query][k]<<" "<<course[k]<<endl;
		}
	}
}
