//��׺���ʽ
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
stack<node> s;		//1.��ʱ�洢������ 2.�ں�׺���ʽ��ֵ�д洢�м���ֵ
queue<node> q;		//��׺���ʽ����
map<char,int> op;

void Change() {
	double num;
	node temp;
	for(int i=0; i<str.length(); i++) {
		if(isdigit(str[i])) {		//���������
			temp.flag=true;
			temp.num=str[i++]-'0';
			while(i<str.length() && isdigit(str[i])) {
				temp.num=temp.num*10+(str[i++]-'0');
			}
			q.push(temp);		//�����������ѹ���׺���ʽ�Ķ��� 
		}else{
			temp.flag = false;
			//ֻҪջ��Ԫ�ص����ȼ����ڵ��ڲ����������ȼ���
			//�Ͱ�ջ��Ԫ��push����q��
			while(!s.empty() && op[s.top().op]>=op[str[i]]){
				q.push(s.top());
				s.pop();
			}
			temp.op = str[i];
			s.push(temp);
			i++;
		}
		
		//���������ջ�л��в��������Ͱ�����������׺���ʽ������
		while(!s.empty()){
			q.push(s.top());
			s.pop();
		} 
	}
}
//�����׺���ʽ 
double Cal() {
	double temp1,temp2;
	node cur,temp;
	while(!q.empty()){		//ֻҪ��׺���ʽ�ǿ� 
		cur=q.front();
		q.pop();
		if(cur.flag==true)	s.push(cur);		//����ǲ�������ֱ��ѹ��ջ��
		else{		//����ǲ����� 
			temp2 = s.top().num;		//�ڶ�������
			s.pop();
			temp1= s.top().num;
			s.pop();
			temp.flag=true;			//��ʱ��¼������
			if(cur.op == '+') temp.num=temp1+temp2;
			else if(cur.op == '-') temp.num=temp1-temp2;
			else if(cur.op == '*') temp.num=temp1*temp2;
			else if(cur.op == '/') temp.num=temp1/temp2;
			s.push(temp);
		} 
	}
	return s.top().num;		//ջ��Ԫ�ؾ��Ǻ�׺���ʽ��ֵ 
}

int main() {
	op['+'] =op['-']=1;
	op['*'] =op['/']=2;
	while(getline(cin,str),str!="0") {
		//����ΪʲôҪ�Ӻ���ǰ�� ,������Ϊ��str��û�к���space
		for(auto it=str.end(); it!=str.begin(); it--) {
			if(*it==' ') str.erase(it);
		}
		while(!s.empty()) s.pop();	//��ʼ��ջ
		Change();		//��׺ת��׺
		printf("%.2f\n",Cal());		//�����׺���ʽ
	}
}


