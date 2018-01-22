#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
struct Student {
	string id;
	int score;
	int loc_no;
	int loc_rank;
} stu[30010];

bool cmp(Student a,Student b) {
	if(a.score!=b.score) return a.score>b.score;
	else return a.id<b.id;
}

int main() {
	int n,k,num=0;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>k;
		for(int j=0; j<k; j++) {
			cin>>stu[num].id>>stu[num].score;
			stu[num].loc_no=i;
			num++;
		}
		sort(stu+num-k,stu+num,cmp);		//将该考场的考生排序
		stu[num-k].loc_rank=1;		//该考场第一名loc_rank记为1
		for(int j=num-k+1; j<num; j++) {
			if(stu[j].score == stu[j-1].score) {
				stu[j].loc_rank = stu[j-1].loc_rank;
			} else {
//				stu[j].loc_rank = stu[j-1].loc_rank+1;
				stu[j].loc_rank = j+1-(num-k);
			}
		}
	}
	//输出总考生人数
	cout<<num<<endl;
	sort(stu,stu+num,cmp);
	int r=1;
	for(int i=0; i<num; i++) {
		if(i>0 && stu[i].score != stu[i-1].score) {
			r=i+1;
		}
		printf("%s %d %d %d\n",stu[i].id.c_str(),r,stu[i].loc_no,stu[i].loc_rank);
	}
}
