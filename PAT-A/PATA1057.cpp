//PATA1057
#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
const int maxn=100010;
const int sqrN=316;
stack<int> st;
int block[sqrN];
int table[maxn];

void Push(int x){
	st.push(x);
	block[x/sqrN]++;
	table[x]++;
}

void Pop(){
	int x=st.top();
	st.pop();
	block[x/sqrN]--;
	table[x]--;
	printf("%d\n",x);
} 

void peekMedian(int K){
	int sum=0;
	int idx=0;
	while(sum+block[idx] < K){
		sum += block[idx++];
	}
	int num=idx*sqrN;	//idx号块的第一个数
	while(sum+table[num] < K){
		sum += table[num++];
	}
	printf("%d\n",num);
}

int main(){
	int x,query;
	char cmd[20];
	scanf("%d",&query);
	for(int i=0;i<query;i++){
		scanf("%s",cmd);
		if(strcmp(cmd,"Push")==0){
			scanf("%d",&x);
			Push(x);
		}else if(strcmp(cmd,"Pop")==0){
			if(st.empty()){
				printf("Invalid\n");
			}else{
				Pop();
			}
		}else{
			if(st.empty()){
				printf("Invalid\n");
			}else{
				int K=st.size();
				if(K%2==1) K=(K+1)/2;
				else K=K/2;
				peekMedian(K); 
			} 
		}
	}
}
