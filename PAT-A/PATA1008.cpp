//PATA1008
#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
int N;
int main(){
	cin>>N;
	v.push_back(0);		//°Ñ0´æ½øÈ¥ 
	for(int i=1;i<=N;i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	int up=0,down=0,stop=0;
	for(int i=1;i<=N;i++){
		if(v[i]>v[i-1]){
			up+=v[i]-v[i-1];
		}
		else if(v[i]<v[i-1]){
			down+=v[i-1]-v[i];
		}
	}
	stop=N;
	int ans = up*6+down*4+stop*5;
	cout<<ans;
} 
