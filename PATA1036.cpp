//PATA1036
#include <cstdio>
struct person {
	char name[11];
	char gender;
	char id[11];
	int grade;
} temp, female, male;

bool great(person a, person b) {
	return a.grade>b.grade;
}

int main() {
	int N;
	scanf("%d",&N);
	//��ʼ��Ů���ɼ�Ϊ���-1
	female.grade=-1;
	//��ʼ�������ɼ�Ϊ���101
	male.grade=101;
	for(int i=0; i<N; i++) {
		scanf("%s %c %s %d",temp.name,&temp.gender,temp.id,&temp.grade);
		if(temp.gender=='F'&& great(temp,female) ) {	//��Ů�����ҳɼ�����female
			female=temp;
		}
		if(temp.gender=='M'&& !great(temp,male) ) {	//���������ҳɼ�С��male
			male=temp;
		}
	}
	bool right=true;
	if(female.grade==-1) {
		printf("Absent\n");
		right=false;
	} else {
		printf("%s %s\n",female.name,female.id);
	}
	if(male.grade==101) {
		printf("Absent\n");
		right=false;
	} else {
		printf("%s %s\n",male.name,male.id);
	}
	if(right == false){
		printf("NA\n");
	}else{
		printf("%d\n",female.grade-male.grade);
	}
	return 0;
}
