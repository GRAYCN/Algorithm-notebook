#include <stdio.h>

int change(char c){		//BΪ0��CΪ1��JΪ2��ǡ����ѭ����˵�˳�򣬶����ֵ������ 
	if(c=='B') return 0;
	if(c=='C') return 1;
	if(c=='J') return 2;
}

int main(){
	char mp[3]={'B','C','J'};
	int n;
	scanf("%d",&n);
	int times_A[3]={0},times_B[3]={0};		//�ֱ��¼���ҵ�ʤƽ������
	int hand_A[3]={0},hand_B[3]={0};		//����BCJ˳���¼����3�����ƵĻ�ʤ˳��
	char c1,c2;
	int k1,k2;
	for(int i=0;i<n;i++){
		getchar();
		scanf("%c %c",&c1,&c2);					//������ҵ�����
		k1=change(c1);
		k2=change(c2);
		if( (k1+1)%3 == k2 ){   	//�����ʤ�� 
			times_A[0]++;
			times_B[2]++;
			hand_A[k1]++;
		}else if(k1==k2){
			times_A[1]++;
			times_B[1]++;
		}else{
			times_A[2]++;
			times_B[0]++;
			hand_B[k2]++;
		} 		 
	}
	printf("%d %d %d\n",times_A[0],times_A[1],times_A[2]);
	printf("%d %d %d\n",times_B[0],times_B[1],times_B[2]);
	int idA=0,idB=0;
	for(int i=0;i<3;i++){
		if(hand_A[i]>hand_A[idA])
			idA=i;
		if(hand_B[i]>hand_B[idB])
			idB=i;
	}	 
	printf("%c %c\n", mp[idA],mp[idB]);
	return 0;
}
