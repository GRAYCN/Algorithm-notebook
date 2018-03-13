//PATA1006
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int M;
struct Node{
	string ID;
	string signInTime,signOutTime;
}node[1000];

int cmpBySignInTime(Node a, Node b){
	return a.signInTime<b.signInTime;
}

int cmpBySignOutTime(Node a, Node b){
	return a.signOutTime>b.signOutTime;
}

int main(){
	cin>>M;
	for(int i=0;i<M;i++){
		cin>>node[i].ID>>node[i].signInTime>>node[i].signOutTime;
	}
	sort(node,node+M,cmpBySignInTime);
	cout<<node[0].ID<<" ";
	sort(node,node+M,cmpBySignOutTime);
	cout<<node[0].ID;
} 
