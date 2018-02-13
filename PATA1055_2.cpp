#include <iostream>
#include<cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Man {
	char name[9];
	int age;
	int worth;
} ;

Man p[100005];
int cmp(Man a, Man b) {
	if(a.worth!=b.worth) return a.worth>b.worth;
	else{
		if(a.age!=b.age) return a.age<b.age;
		else return strcmp(a.name,b.name)<0;	
	} 
}

int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0; i<n; i++) {
		scanf("%s%d%d",p[i].name,&p[i].age,&p[i].worth);
	}
	sort(p,p+n,cmp);
		int m,min,max;
	for(int i=1; i<=k; i++) {

		printf("Case #%d:\n",i);
		scanf("%d%d%d",&m,&min,&max);

		//遍历p[]，找寻并输出在范围内的人
		int count=0;
		for(int j=0; j<n; j++) {
			if(p[j].age>=min && p[j].age<=max ) {
				printf("%s %d %d\n",p[j].name,p[j].age,p[j].worth);
				count++;
				if(count==m) break;
			}
		}
		if(count==0)
			printf("None\n");
	}
}
