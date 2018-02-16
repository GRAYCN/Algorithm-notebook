//
//  main.cpp
//  A1036
//
//  Created by mac on 18/2/16.
//  Copyright (c) 2018年 mac. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
#define maxn 100000

struct Student{
    string name;
    char gender;
    string ID;
    int grade;
}girl,boy;


int main(int argc, const char * argv[]) {
    int N;
    cin>>N;
    string name;
    char gender;
    string ID;
    int grade;
    girl.grade=-1;
    boy.grade=101;
    for (int i=0; i<N; i++) {
        cin>>name>>gender>>ID>>grade;
        if (gender=='F' && grade>girl.grade) {
            girl.name=name;
            girl.gender=gender;
            girl.ID=ID;
            girl.grade=grade;
        }
        if (gender=='M' && grade<boy.grade) {
            boy.name=name;
            boy.gender=gender;
            boy.ID=ID;
            boy.grade=grade;
        }
    }
    int flag=true;
    if (girl.grade!=-1) {
        cout<<girl.name<<" "<<girl.ID<<endl;
    }else{
        flag=false;
        cout<<"Absent"<<endl;
    }
    
    if (boy.grade!=101) {
        cout<<boy.name<<" "<<boy.ID<<endl;
    }else{
        flag=false;
        cout<<"Absent"<<endl;
    }
    if (flag) {
        cout<<girl.grade-boy.grade;
    }else{
        cout<<"NA";
    }
    return 0;
}
