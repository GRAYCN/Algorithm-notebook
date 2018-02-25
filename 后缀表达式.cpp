//后缀表达式
#include<iostream>
#include<cstdio>
#include<string>
#include<stack>
#include<queue>
#include<map>

using namespace std;

struct node {
	double num;
	char op;
	bool flag;
};

string str;
stack<node> s;		//1.临时存储操作数 2.在后缀表达式求值中存储中间数值
queue<node> q;		//后缀表达式序列
map<char,int> op;

void Change() {
	double num;
	node temp;
	for(int i=0; i<str.length(); i++) {
		if(isdigit(str[i])) {		//如果是数字
			temp.flag=true;
			temp.num=str[i++]-'0';
			while(i<str.length() && isdigit(str[i])) {
				temp.num=temp.num*10+(str[i++]-'0');
			}
			q.push(temp);		//把这个操作数压入后缀表达式的队列 
		}else{
			temp.flag = false;
			//只要栈顶元素的优先级高于等于操作数的优先级，
			//就把栈顶元素push进入q中
			while(!s.empty() && op[s.top().op]>=op[str[i]]){
				q.push(s.top());
				s.pop();
			}
			temp.op = str[i];
			s.push(temp);
			i++;
		}
		
		//如果操作符栈中还有操作符，就把它弹出到后缀表达式队列中
		while(!s.empty()){
			q.push(s.top());
			s.pop();
		} 
	}
}
//计算后缀表达式 
double Cal() {
	double temp1,temp2;
	node cur,temp;
	while(!q.empty()){		//只要后缀表达式非空 
		cur=q.front();
		q.pop();
		if(cur.flag==true)	s.push(cur);		//如果是操作数，直接压入栈中
		else{		//如果是操作符 
			temp2 = s.top().num;		//第二操作符
			s.pop();
			temp1= s.top().num;
			s.pop();
			temp.flag=true;			//临时记录操作数
			if(cur.op == '+') temp.num=temp1+temp2;
			else if(cur.op == '-') temp.num=temp1-temp2;
			else if(cur.op == '*') temp.num=temp1*temp2;
			else if(cur.op == '/') temp.num=temp1/temp2;
			s.push(temp);
		} 
	}
	return s.top().num;		//栈顶元素就是后缀表达式的值 
}

int main() {
	op['+'] =op['-']=1;
	op['*'] =op['/']=2;
	while(getline(cin,str),str!="0") {
		//这里为什么要从后向前呢 ,可能是为了str的没有后置space
		for(auto it=str.end(); it!=str.begin(); it--) {
			if(*it==' ') str.erase(it);
		}
		while(!s.empty()) s.pop();	//初始化栈
		Change();		//中缀转后缀
		printf("%.2f\n",Cal());		//计算后缀表达式
	}
}


