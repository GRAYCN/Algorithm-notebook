#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct bign {
	int d[1000];
	int len;
	bign() {
		memset(d,0,sizeof(d));
		len=0;
	}
};

bign change(string str) {
	bign a;
	a.len = str.length();
	for(int i=0; i<a.len; i++) {
		a.d[i]=str[a.len-i-1]-'0';
	}
	return a;
}

int compare(big a,big b) {
	if(a.len>b.len) return 1;		//a��
	else if(a.len<b.len) return -1;
	else {
		for(int i=a.len-1; i>=0; i--) {		//�Ӹ�λ����λ���бȽ�
			if(a.d[i]>b.d[i]) return 1;
			esle if(a,d[i]<b.d[i]) return -1;
		}
		return 0;			//�������
	}
}

//�߾��ȼӷ�
bign add(bign a, bign b) {
	bign c;
	int carry = 0;
	for(int i=0; i<a.len || i<b.len; i++) {
		int temp = a.d[i]+b.d[i]+carry;
		c.d[c.len++]=temp%10;		//��λ��Ϊ��λ���
		carry = temp/10;			//ʮλ��Ϊ�µĽ�λ
	}
	if(carry != 0) {		//�������λ��Ϊ0����ֱ�Ӹ�ֵ����������λ
		c.d[c.len++] = carry;
	}
}

//�߾��ȼ���
bign sub(bign a, bign b) {
	bign c;
	for(int i=0; i<a.len || i<b.len; i++) {
		if(a.d[i]<b.d[i]) {	//�����������Ҫ���λ��λ
			a.d[i+1]--;
			a.d[i]+=10;		
		}
		c.d[c.len++] = a.d[i]-b.d[i]; 
	}
	while(c.len - 1 >= 1 && c.d[c.len-1] == 0){
		c.len--;		//ȥ����λ��0��ͬʱ���ٱ���һλ���λ 
	}
	return c;
}

bign multi(bign a, int b){		//�߾��ȳ˷� 
	bign c;
	int carry = 0;
	for(int i=0;i<a.len;i++){
		int temp = a.d[i]*b+carry;
		c.d[c.len++]=temp%10;
		carry = temp/10;
	}
	while(carry != 0){			//�ͼӷ���һ�����˷��Ľ�λ���ܲ�ֹһλ���������ʹ��while 
		c.d[c.len++] = carry%10;
		carry/=10;
	}
	return c;
}

//�߾��ȳ������� 
bign divide(bign a, int b, int& r){
	bign c;
	c.len=a.len;		//��������ÿһλ���̵�ÿһλ��һһ��Ӧ�ģ������������
	for(int i=a.len-1;i>=0;i--){	//�Ӹ�λ��ʼ 
		r = r*10+a.d[i];		//����һλ������������� ����
		if(r<b) c.d[i]=0;
		else{
			c.d[i]=r/b;
			r=r%b;	
		} 
	} 
	while(c.len-1 >=1 && c.d[c.len-1] ==0){
		c.len--;		//ȥ����λ��0��ͬʱ���ٱ���һλ���λ 
	}
	return c; 
}

int main() {

}
