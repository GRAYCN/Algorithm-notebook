//1�֡�������Ҳ̫�����˰ɡ�����
 //ģ���ջ��ջ�Ĳ�������Ҫע���������ջ��������������������Բ���Ҫ�������ݽṹ�ϵ�
//��ȷ����Ҫȷ�����ᱬջ
#include<cstdio>
#include<stack>
#define maxn 1010
using namespace std;
stack<int> s;
int M,N,K;
int a[maxn];
int main() {
	scanf("%d%d%d",&M,&N,&K);
	for(int i=0; i<K; i++) {
		
		int k=1;		//��¼ģ����ջ�����ֵ
		bool flag = true;
		//ÿһ�ֶ���ջ���
		while(!s.empty()) s.pop();
		for(int i=0;i<N;i++){
			scanf("%d",&a[i]);
		}
		for(int i=0; i<N; i++) {
			//�����ѯ���е�ǰ��temp����ջ��ջ������ôs.pushֱ������tempλ��,���û�б�ջ��temp����
			//��� tempС��ջ��ջ������ô����
			int temp;	//��¼ÿ�����������
			temp=a[i];
			while(s.empty() || temp>s.top()) {
				s.push(k++);
				//��ջ
				if(s.size()>M) {
					printf("NO\n");
					flag=false;
					break;
				}
			} 
			if(flag==false)
				break;
			if(temp<s.top()) {
				flag=false;
				printf("NO\n");
				break;
			}
			//�����������temp== s.top() ģ��s.pop
			s.pop(); 
		}
		if(flag==true)
			printf("YES\n");
	}
}
