// ͨ��ֻ����0ʵ�ֽ�����˳������
//�۲�0��λ�ã�
//1.���0����0��λ�ã��ͽ�0����λ�õ��±���������ڵ�λ����0���ڵ�λ�ý���
//2.���0�Ѿ���λ����ô�ͽ�0�ͱ��������е�һ�����ڱ�λ�õ����ֽ���
//line39 ��Щ��������� 
#include<iostream>
#include<algorithm>
#define maxn 100005
using namespace std;

int pos[maxn];		//��¼����i������λ��
int main() {
	int N;
	cin>>N;
	int left=N-1;		//��¼��0���⻹û�й�λ�ĸ���
	for(int i=0; i<N; i++) {
		int num;
		cin>>num;
		pos[num]=i;
		if(num==i && num!=0) {
			left--;
		}
	}

	//��ʼѭ��������ֱ��leftΪ0Ϊֹ
	int count=0;
	int k=0;		//��һ�����ڱ�λ�ϵ�����
	while(left) {
		//���0���ڱ�λ�ϣ�����pos[pos[0]]��pos[0]
		while(pos[0]!=0) {
			swap(pos[pos[0]],pos[0]);
			count++;
			left--;
		}

		//���0���ڱ�λ�ϣ���ôѰ�Ҵ����ҵ�һ�����ڱ�λ�ϵ����ֺ�0����
		if(pos[0]==0) {
			while(k<N-1) {
				k++;
				if(k==N-1)
					break;
				else if(k!=pos[k]) {
					swap(pos[k],pos[0]);
					count++;
					break;
				}
			}
		}
	}
	cout<<count;
}

