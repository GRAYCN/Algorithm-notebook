//PATA1089
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> ori,middle,insert_seq,merge_seq;

bool flag = true;		//is merge sort
int N;
void insert_sort(){
	insert_seq=ori;
	for(int i=2;i<=insert_seq.size();i++){
		sort(insert_seq.begin(),insert_seq.begin()+i);
		if(insert_seq == middle){
			flag=false;
			sort(insert_seq.begin(),insert_seq.begin()+i+1);
			break;
		}
	}
	if(flag==false){
		//print
		cout<<"Insertion Sort"<<endl;
		for(int i=0;i<insert_seq.size();i++){
			cout<<insert_seq[i];
			if(i!=insert_seq.size()-1) cout<<" ";
		}
	}
}

void merge_sort(){
	merge_seq=ori;
	bool flag2=false;
	for(int step=2;step/2<=N;step*=2){
		if(merge_seq==middle){
			flag2=true;
		}
		for(int i=0;i<N;i+=step){
			sort(merge_seq.begin()+i,merge_seq.begin()+min(i+step,N));
		}
		if(flag2==true){
			cout<<"Merge Sort"<<endl;
			for(int i=0;i<merge_seq.size();i++){
				cout<<merge_seq[i];
				if(i!=merge_seq.size()-1) cout<<" ";
		  	}
		  	return;
		}
	}
}

int main(){

	cin>>N;
	for(int i=0;i<N;i++){
		int temp;
		cin>>temp;
		ori.push_back(temp);
	}
	for(int i=0;i<N;i++){
		int temp;
		cin>>temp;
		middle.push_back(temp);
	}
	insert_sort();
	if(flag==true){
		merge_sort();
	}	
} 
