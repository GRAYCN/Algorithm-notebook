//PATA1103
#include<cstdio>
#include<vector>
#include<math.h>
using namespace std;
int N,K,P;
vector<int> temp,ans;		//temp�����ʱ������ans���ƽ�������ķ��� 
int maxSumFactor=-1;
void DFS(int index,int num,int sum,int sumFactor){

	//�������� 
	//if(index>=0 && num==K && sum==N){
	if(num==K && sum==N){
		if(sumFactor>maxSumFactor){
			maxSumFactor=sumFactor;
			ans=temp;
		}
		return;
	}
	//��indexС��0��num����K,sum����N���ͻ�����
	//if(index<0 || num>K || sum>N)
	if(num>K || sum>N)
		return;

	//ѡ��index���� 
	if(index-1>=0){
		temp.push_back(index);
		DFS(index,num+1,sum+pow(index,P*1.0),sumFactor+index);
		temp.pop_back();
		//��ѡ��index����
		DFS(index-1,num,sum,sumFactor);
	}

}

int main(){
	scanf("%d%d%d",&N,&K,&P);
	int nowK=0;
	int index= sqrt(1.0*N);
	DFS(index,0,0,0);
	if(ans.size()!=0){
		printf("%d = ",N);
		for(int i=0;i<ans.size();i++){
			if(i!=0) printf(" + ");
			printf("%d^%d",ans[i],P);
		}
	}else{
		printf("Impossible");
	}
}
