//PATA1112_2
#include <iostream>
using namespace std;
#include <set>
#include <vector>
#include <string>
int k;
string str;
string right_str;
vector<char> RightKey_vector;
bool isRight[256];

int main()
{
	cin>>k>>str;
	int num=1;		//记录遍历点之前的一个char的重复次数
	str+='#';		//增加一个哨兵,简化运算
	for (int i=1;i<str.length();i++)
	{
		if(str[i]!=str[i-1] )
		{
			if (num%k!=0)
			{
				isRight[str[i-1]]=true; 
			}
			num = 1;			//将Num重新置为1
		}
		else{
			num++;
		}
	}
	bool hasOutput[256]={false};
	//将问题键输出
	for(int i=0;i<str.length()-1;i++){
		if(!isRight[str[i]] && !hasOutput[str[i]]){
			printf("%c",str[i]);
			hasOutput[str[i]]=true; 
		} 
	}
	printf("\n");
	
	//output the right text
	for(int i=0;i<str.length()-1;i++){
		printf("%c",str[i]);
		if(!isRight[str[i]])
			i+=k-1;
	}
	return 0;
}
