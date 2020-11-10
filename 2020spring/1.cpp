//
// Created by w on 2020/11/10.
//

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int num){
    if(num==1) return false;
    for (int i = 2; i <= sqrt(1.0 * num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main(){
    string str;
    cin>>str;
    int bg = 0, ed = str.size();
    bool flag = true;
    while (bg < ed) {
        string tmp = str.substr(bg, ed);
        printf("%s ", tmp.c_str());
        if (isPrime(atoi(tmp.c_str()))) {
            printf("Yes\n");
        }else{
            printf("No\n");
            flag = false;
        }
        bg++;
    }
    if (flag) {
        printf("All Prime!\n");
    }
}
