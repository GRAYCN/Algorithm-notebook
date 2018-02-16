//
//  main.cpp
//  A1006
//
//  Created by mac on 18/2/16.
//  Copyright (c) 2018年 mac. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define maxn 100000
struct Person{
    string name;
    string sign_in_time,sign_out_time;
}per[maxn];

int cmpBySignInTime(Person a, Person b){
    return a.sign_in_time<b.sign_in_time;
}

int cmpBySignOutTime(Person a, Person b){
    return a.sign_out_time>b.sign_out_time;
}

int main(int argc, const char * argv[]) {
    int M;
    cin>>M;
    int cnt=0;
    for (int i=0; i<M; i++) {
        cin>>per[i].name>>per[i].sign_in_time>>per[i].sign_out_time;
        cnt++;
    }
    sort(per, per+cnt, cmpBySignInTime);
    cout<<per[0].name;
    
    cout<<" ";
    
    sort(per, per+cnt, cmpBySignOutTime);
    cout<<per[0].name;
    return 0;
}
