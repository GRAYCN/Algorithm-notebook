//������Ϊʲô�ᳬʱ�����ú�û�е������� 
//PATA1063
#include<cstdio>
#include<set>
using namespace std;
set<int> a[52],Nc,Nt;

int main(){
	int N,M;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d",&M);
		for(int j=0;j<M;j++){
			int temp;
			scanf("%d",&temp);
			a[i].insert(temp);
		}	
	}
	int K;
	scanf("%d",&K);	
	int p,q;
	for(int i=0;i<K;i++){
		scanf("%d%d",&p,&q);
		//�������Nc��Nk
		Nc.clear();
		Nt.clear(); 
		
		//�����ߵĹ������ִ洢��Nc��
		set<int>::iterator it1=a[p].begin();
		set<int>::iterator it2 = a[q].begin();
		while(it1!=a[p].end() && it2!=a[q].end()){
			if(*it1>*it2){
				it2++;
			}else if(*it1<*it2){
				it1++;
			}else{
				Nc.insert(*it1);
				it1++;
				it2++;
			}
		}
		
		//������ȫ����ӽ���Nk��
			it1=a[p].begin();
			it2 = a[q].begin();
			for(;it1!=a[p].end();it1++){
				Nt.insert(*it1);
			}	
			for(;it2!=a[q].end();it2++){
				Nt.insert(*it2);
			}	
		//������������
		double result = 100.0 * Nc.size()/Nt.size();  
		printf("%.1f%\n",result);
	}
}
