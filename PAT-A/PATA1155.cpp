//
// Created by w on 2020/11/8.
//



#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
// todo
using namespace std;

struct node{
    int v=-1;
    int l;
    int r;
}n[1005];

void print(vector<int>& res){
    for(int i=0;i<res.size();i++){
        if(i>0) printf(" ");
        printf("%d", res[i]);
    }
    printf("\n");
}


void DFS(int index, vector<int>& res, int N, bool& isMax, bool& isMin){
    res.push_back(n[index].v);
    if(n[index].r > N && n[index].l > N){
//         res.push_back(n[index].v);
        print(res);
        vector<int> temp = res;
        vector<int> rtemp = res;
        sort(temp.begin(), temp.end());
        sort(rtemp.begin(), rtemp.end(),greater<int>());
        if(temp != res) isMin=false;
        if(rtemp != res) isMax=false;
        res.pop_back();
        return ;
    }

//     res.push_back(n[index].v);
    if( n[index].r < N )
        DFS(n[index].r, res,N,isMax,isMin);
    if( n[index].l < N )
        DFS(n[index].l, res,N,isMax,isMin);
    res.pop_back();
}

int main(){
    int N;
    cin>>N;
    for(int i = 0;i < N;i++){
        cin>>n[i].v;
    }

    for(int i=0;i<N;i++){
        n[i].l = i*2+1;
        n[i].r = i*2+2;
    }

    vector<int> res;
    bool isMax = true, isMin = true;
    DFS(0, res, N, isMax, isMin);

    if((isMax&&isMin) || (!isMax&&!isMin)) printf("Not Heap\n");
    else if(isMax) printf("Max Heap\n");
    else printf("Min Heap\n");
}

