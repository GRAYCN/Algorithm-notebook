//1分。。。这也太残忍了吧。。。
 //模拟出栈入栈的操作，需要注意的陷阱是栈自身有其最大容量，所以不光要满足数据结构上的
//正确，还要确保不会爆栈
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
		
		int k=1;		//记录模拟入栈的最大值
		bool flag = true;
		//每一轮都将栈清空
		while(!s.empty()) s.pop();
		for(int i=0;i<N;i++){
			scanf("%d",&a[i]);
		}
		for(int i=0; i<N; i++) {
			//如果查询队列当前的temp大于栈的栈顶，那么s.push直到等于temp位置,检查没有爆栈后将temp弹出
			//如果 temp小于栈的栈顶，那么报错
			int temp;	//记录每次输入的内容
			temp=a[i];
			while(s.empty() || temp>s.top()) {
				s.push(k++);
				//爆栈
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
			//正常情况，即temp== s.top() 模拟s.pop
			s.pop(); 
		}
		if(flag==true)
			printf("YES\n");
	}
}
