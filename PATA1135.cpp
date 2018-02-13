//PATA1135
/*
15бо 
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include <cmath>
using namespace std;

struct Node{
	int data;
	string color;
	int lchild,rchild;	
}node[1000000];
vector<int> pre,in;
vector<int> path, numOfBlack;
int root;

int num=0;
bool flag=true;
void check(int index){
	if(index==-1) return;
	if(node[index].lchild==-1 && node[index].rchild==-1){
		path.push_back(index);
		int cnt=0;
		for(int i=0;i<path.size();i++){
			int id=path[i];
			if(node[id].color=="black"){
				cnt++;
			}
		}
		numOfBlack.push_back(cnt);
		path.pop_back();
		return;
	}
	path.push_back(index);
	check(node[index].lchild);
	check(node[index].rchild);
	path.pop_back();
}

bool isSame(int index){
	check(index);

	int x=numOfBlack[0];
	for(int i=0;i<numOfBlack.size();i++){
		if(numOfBlack[i]!=x){
			return false;
		}
	}

	return true;
}

void DFS(int index){
	if( (node[index].lchild!=-1 || node[index].rchild!=-1) ){
		if(node[index].color=="red"){
			int id1=node[index].lchild,id2=node[index].rchild;
			if (node[id1].color=="red" ||node[id2].color=="red")
			{
				printf("No\n");
				flag=false;
				return;
			}
		}
		path.clear();
		numOfBlack.clear();
		if(!isSame(index)){
			printf("No\n");
			flag=false;
			return;
		}	
	}
	if(node[index].lchild!=-1) DFS(node[index].lchild);
	//if(flag==false) return;
	if(node[index].rchild!=-1) DFS(node[index].rchild);
	//if(flag==false) return;
}

int build(int preL,int preR,int inL,int inR){
	if(preL>preR){
		return -1;
	}
	int root = pre[preL];
	//bool negative=false;
	if (root<0)
	{
		//negative=true;
		root=-root;
		node[root].color="red";
	}else{
		node[root].color="black";
	}
	int k;
	for(k=inL;k<=inR;k++){
		if(abs(in[k])==root){
			break;
		}
	}
	int numLeft=k-inL;
	node[root].lchild=build(preL+1,preL+numLeft,inL,k-1);
	node[root].rchild=build(preL+numLeft+1,preR,k+1,inR);
	return root;
}

int cmp(int a,int b){
	return abs(a)<abs(b);
}

int main(){
	int K,N;
	cin>>K;
	for(int i=0;i<K;i++){
		cin>>N;
		pre.resize(N);
		in.resize(N);
		for(int j=0;j<N;j++){
			cin>>pre[j];
		}
		in=pre;
		sort(in.begin(),in.end(),cmp);
		root = build(0,N-1,0,N-1);
		if(node[root].color=="red"){
			cout<<"No"<<endl;
			continue;
		}
		flag=true;
		//if(pre[0]==10){
		//	printf("");
		//}
		DFS(root);	
		if(flag==true) cout<<"Yes"<<endl;
	} 
}
