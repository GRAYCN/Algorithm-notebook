#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct student{
	int id;			//����id 
	int d;			//�·� 
	int c;			//�ŷ� 
	int cate;		//�����鵵 1-5
}stu[100005];

/*�������ݣ�  
 1. cate��С����
 2.�ִܷӴ�С
 3.D �Ӵ�С
 4. id��С���� 
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
	//���뿼������ 
	for(int i=0;i<n;i++){
		cin>>stu[i].id>>stu[i].d>>stu[i].c;
		//�Կ����ķ�������б�
		if(stu[i].d>=h && stu[i].c>=h)	stu[i].cate=1;
		else if(stu[i].d>=h && stu[i].c<h && stu[i].c>=l)	stu[i].cate=2;
		else if(stu[i].d<h && stu[i].c<h && stu[i].c>=l 
		&& stu[i].d>=l && stu[i].d>=stu[i].c)	stu[i].cate=3;
		else if(stu[i].c>=l && stu[i].d>=l) stu[i].cate = 4;
		else stu[i].cate = 5;
	}
	//����
	 sort(stu,stu+n,cmp);
	 //�ҵ�cate��Ϊ5�ĸ���
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
