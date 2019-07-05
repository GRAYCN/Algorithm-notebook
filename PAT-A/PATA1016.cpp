//PATA1016
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 1010;
int toll[25];

struct Record{
	char name[25];			//姓名 
	int month,dd,hh,mm;		//月份，日，时，分
	bool status;			//true表示online否则表示offline 
}rec[maxn],temp;

bool cmp(Record a, Record b){
	//按照name字典序从小到大
	if(strcmp(a.name,b.name)!=0) return strcmp(a.name,b.name)<0;
	//month从小到大
	else if(a.month!=b.month) return a.month<b.month;
	//	dd从小到大	
	else if(a.dd!=b.dd) return a.dd<b.dd;
	//	hh从小到大
	else if(a.hh!=b.hh) return a.hh<b.hh; 
	// 	mm从小到大 
	else if(a.mm!=b.mm) return a.mm<b.mm;
} 

void get_ans(int on,int off, int& time, int& money){
	temp = rec[on];
	while(temp.dd<rec[off].dd || temp.hh<rec[off].hh 
		|| temp.mm<rec[off].mm){
			time++;
			money+=toll[temp.hh];		//话费增加toll[temp.hh]
			temp.mm++;
			if(temp.mm>=60){
				temp.mm=0;
				temp.hh++;
			} 
			if(temp.hh>=24){
				temp.hh=0;
				temp.dd++;
			}
	}
}

int main(){
	for(int i=0;i<24;i++){
		cin>>toll[i];		//每个小时段的收费 
	}
	int n;
	cin>>n;
	char line[10];
	for(int i=0;i<n;i++){
		scanf("%s",rec[i].name);
		scanf("%d:%d:%d:%d",&rec[i].month,&rec[i].dd,&rec[i].hh,
			&rec[i].mm);
		scanf("%s",line);
		if(strcmp(line,"on-line")==0) rec[i].status=true;
		else rec[i].status=false;
	}
	sort(rec,rec+n,cmp);
	//进行配对模拟，这里是重点
	int on=0,off,next;		//on和off为配对的两条记录，next为下一个用户
	while(on<n){
		int needPrint=0;
		next=on;
		//该处只是判断是否存在配对，并找出下一个用户的起始下标存在Index中 
		while(next<n && strcmp(rec[next].name,rec[on].name)==0){
			if(needPrint==0&&rec[next].status==true){
				needPrint=1;
			}else if(needPrint==1&&rec[next].status==false){
				needPrint=2;		//在On之后如果找到off,置needPrint为2 
			}
			next++;
		}if(needPrint<2){			//没有找到配对的on-off 
			on = next;			//什么意思？ 
			continue;
		}
		int AllMoney = 0;			//总共花费的钱
		printf("%s %02d\n",rec[on].name,rec[on].month);
		while(on<next){
			while(on<next -1 
				&&!(rec[on].status== true && rec[on+1].status==false)){
					on++;		//直到找到连续的online和offline 
			}
			off=on+1;
			if(off==next){		//已经输出完所有配对 online和offline 
				on=next;
				break;
			}
			printf("%02d:%02d:%02d ",rec[on].dd,rec[on].hh,rec[on].mm);	 
			printf("%02d:%02d:%02d ",rec[off].dd,rec[off].hh,rec[off].mm);
			int time=0,money=0;		//时间和单次记录的花费
			get_ans(on,off,time,money);
			AllMoney+=money;
			printf("%d $%.2f\n",time,money/100.0);
			on=off+1;			//finish a peidui,find the next pair from off+1
		}
		printf("Total amount: $%.2f\n",AllMoney/100.0); 
	} 
}
