#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct student{
	int id;			//考生id 
	int d;			//德分 
	int c;			//才分 
	int cate;		//考生归档 1-5
}stu[100005];

/*排序依据：  
 1. cate从小到大
 2.总分从大到小
 3.D 从大到小
 4. id从小到大 
 */ 
 int cmp(student a,student b){
 	if(a.cate!=b.cate) return a.cate<b.cate;
 	else if((a.c+a.d)!=(b.c+b.d)) return (a.c+a.d)>(b.c+b.d);
 	else if(a.d!=b.d) return a.d>b.d;
 	else return a.id<b.id;
 } 

int main(){
	int n,l,h;
	cin>>n>>l>>h;
	//读入考生数据 
	for(int i=0;i<n;i++){
		cin>>stu[i].id>>stu[i].d>>stu[i].c;
		//对考生的分类进行判别
		if(stu[i].d>=h && stu[i].c>=h)	stu[i].cate=1;
		else if(stu[i].d>=h && stu[i].c<h && stu[i].c>=l)	stu[i].cate=2;
		else if(stu[i].d<h && stu[i].c<h && stu[i].c>=l 
		&& stu[i].d>=l && stu[i].d>=stu[i].c)	stu[i].cate=3;
		else if(stu[i].c>=l && stu[i].d>=l) stu[i].cate = 4;
		else stu[i].cate = 5;
	}
	//排序
	 sort(stu,stu+n,cmp);
	 //找到cate不为5的个数
	 int count = 0;
	 for(int i=0;i<n;i++){
	 	if(stu[i].cate == 5){
	 		break;
		 }
		 count++;
	 } 
	 cout<<count<<endl;
	 for(int i=0;i<count;i++){
	 	printf("%d %d %d\n",stu[i].id,stu[i].d,stu[i].c);
	 }
}
