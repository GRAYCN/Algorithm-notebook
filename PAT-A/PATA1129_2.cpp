//PATA1129_2
#include<cstdio>
#include<set>
using namespace std;
int book[500001];
struct node{
	int value, cnt;
	node(int a,int b):value(a),cnt(b){}
	bool operator < (const node &a) const{
	return(cnt!=a.cnt)? cnt>a.cnt:value<a.value;
	}
};

int main(){
	int n,k,num;
	scanf("%d%d",&n,&k);
	set<node> s;
	for(int i=0;i<n;i++){
		scanf("%d",&num);
		if(i!=0){
			printf("%d:", num);
			int tempCnt = 0;
			for(set<node>::iterator it=s.begin();tempCnt<k && it!=s.end();it++){
				printf(" %d", it->value);
                tempCnt++;
			}
			printf("\n");
		}
		set<node>::iterator it=s.find(node(num,book[num]));
		if(it!=s.end()) s.erase(it);		//why erase it?
		book[num]++;
		s.insert(node(num,book[num]));
		
//		book[num]++;
//		if(it!=s.end()) it->cnt=book[num];
//		else s.insert(node(num,book[num]));
	}	
}
