//PATA1056
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> roundd[1010];
int rankk[1010];
int player[1010];
int Np,Ng;
int main(){
	scanf("%d%d",&Np,&Ng);
	for(int i=0;i<Np;i++){
		scanf("%d",&player[i]);
	}
	for(int i=0;i<Np;i++){
		int index;
		scanf("%d",&index);
		roundd[0].push_back(index);		//the first round
	}
	int cnt=0;
	while(roundd[cnt].size()!=1){
		int group = Np%Ng==0? Np/Ng:Np/Ng+1;
		int max=0;
		for(int i=0;i<roundd[cnt].size();i++){
			if(player[roundd[cnt][i]]>player[max]){
				max=roundd[cnt][i];
			}
			if((i+1)%Ng==0 || i==roundd[cnt].size()-1){
				//				if(max!=-1)
				roundd[cnt+1].push_back(max);
				if (i+1<=roundd[cnt].size()-1)
				{
					max=roundd[cnt][i+1];
				}
				
			}	
		}
		cnt++;
	}

	//rank
	//cnt--;
	int layer=cnt-1;
	rankk[roundd[cnt][0]]=1;
	while(layer>=0){
		for(int i=0;i<roundd[layer].size();i++){
			if(rankk[roundd[layer][i]]==0)
				rankk[roundd[layer][i]]=roundd[layer+1].size()+1;
		}
		layer--;
	}

	for(int i=0;i<Np;i++){
		printf("%d",rankk[i]);
		if(i!=roundd[0].size()-1) printf(" ");
	}
}
