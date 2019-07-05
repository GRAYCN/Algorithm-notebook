//PATA1016_2
//ACÍ¨¹ý 
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int toll[24];
struct record{
	char name[25];
	int mon,d,h,m;
	bool status;		//true online false offline
}rec[1005],temp;

void get_money(int start, int end, int& money, int& time){
	record s= rec[start];
	record e=rec[end];
	while(s.d<e.d || s.h<e.h|| s.m<e.m){
		s.m++;
		time++;
		money+=toll[s.h];
		if(s.m>=60){
			s.m=0;
			s.h++;
		}
		if(s.h>=24){
			s.h=0;
			s.d++;
		}
	}
}

int cmp(record a,record b){
	if(strcmp(a.name,b.name)!=0) return strcmp(a.name,b.name)<0;
	else if(a.d!=b.d) return a.d<b.d;
	else if(a.h!=b.h) return a.h<b.h;
	else if(a.m!=b.m) return a.m<b.m;
}

int main(){
	for(int i=0;i<24;i++){
		cin>>toll[i];			//input toll
	}
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		char line[10];
		scanf("%s %d:%d:%d:%d %s",rec[i].name,&rec[i].mon,&rec[i].d,&rec[i].h,&rec[i].m,line);
		if(strcmp(line,"on-line")==0) rec[i].status=true;
		else rec[i].status=false;
	}
	sort(rec,rec+N,cmp);		//sort
	int on=0,next;

	while(on<N){
		next=on;
		int value=0;
		while(strcmp(rec[next].name,rec[on].name)==0 ){
			if(value==0 && rec[next].status==true){
				value=1;
			}
			else if(value==1 && rec[next].status==false && rec[next-1].status==true){
				value=2;
			}
			next++;
		}
		//next++;
		if(value<2){		//no match
			on=next;
			continue;
		}
		printf("%s %02d\n",rec[on].name,rec[on].mon);
		int i=on;
		double allMoney=0;
		while(i<next){
			while(i<next-1 && !(rec[i].status==true && 
			rec[i+1].status==false)){		//find the match situation
				i++;
				on=i;
			}
			if(i==next-1) break;
			int money=0;
			int time=0;
			get_money(i,i+1,money,time);		//cal the money and time
			allMoney+=money/100.0;
			printf("%02d:%02d:%02d ",rec[i].d,rec[i].h,rec[i].m);
			printf("%02d:%02d:%02d ",rec[i+1].d,rec[i+1].h,rec[i+1].m);
			printf("%d $%.2f\n",time,money/100.0);
			i++;
			on=i;
		}
		printf("Total amount: $%.2f\n",allMoney);
	}
}
