//
//  main.cpp
//  A1011
//
//  Created by mac on 18/2/15.
//  Copyright (c) 2018年 mac. All rights reserved.
//
//why 17'
#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    char mp[4]={"WTL"};
    double ans=1.0;
    for (int i=0; i<3; i++) {
        double maxvalue=0.0;
        int maxchar=0;
        for (int j=0; j<3; j++) {
            double value;
//            cin>>value;
            scanf("%lf", &value);
            if (maxvalue<value) {
                maxvalue=value;
                maxchar=j;
            }
        }
        ans*=maxvalue;
        printf("%c ",mp[maxchar]);
    }
    printf("%.2f",(ans*0.65-1)*2);
}
