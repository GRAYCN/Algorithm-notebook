//PATB1028_2
#include <cstdio>
struct person {
	char name[10];
	int yy,mm,dd;
} oldest,youngest,left,right,temp;
//oldest��youngest������곤����������ˣ�left��right��źϷ����ڵ����ұ߽�

bool LessEqu(person a, person b) {  	//���a������С�ڵ���b�����ڣ�����true
	if(a.yy != b.yy) return a.yy<b.yy;
	else if(a.mm != b.mm) return a.mm<b.mm;
	else return a.dd<b.dd;
}

bool MoreEqu(person a, person b) {  	//���a�����ڴ��ڵ���b�����ڣ�����true
	if(a.yy != b.yy) return a.yy>b.yy;
	else if(a.mm != b.mm) return a.mm>b.mm;
	else return a.dd>b.dd;
}

//youngest��leftΪ1814��9��6�գ�oldest��rightΪ2014��9��6�� 
void init(){
	youngest.yy=left.yy=1814;
	oldest.yy=right.yy=2014;
	youngest.mm=oldest.mm=right.mm=left.mm=9;
	youngest.dd=oldest.dd=right.dd=left.dd=6;
}

int main() {
	init();
	int n,num=0;
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%s%d/%d/%d",temp.name,&temp.yy,&temp.mm,&temp.dd);
		if(MoreEqu(temp,left) && LessEqu(temp,right)){
			//���ںϷ�
			num++;
			if(LessEqu(temp,oldest)){
				oldest=temp;
			} 
			if(MoreEqu(temp,youngest)){
				youngest=temp;
			}
		} 
	}
	//�����ؽ�
	if(num==0) printf("0\n");
	else{
		printf("%d %s %s\n",num,oldest.name,youngest.name);
	} 
	return 0;
}
