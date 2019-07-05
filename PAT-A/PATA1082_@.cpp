#include <cstdio>
using namespace std;
char c[6][5] = {"Shi", "Bai", "Qian", "Wan", "Yi"};
char t[11][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
int a, flag = 0;
void read(int num) {
    int flag1 = 0, flag2 = 0, flag3 = 0;
    if(num / 1000) {
        printf("%s %s", t[num / 1000], c[2]);
        flag1 = 1;
    }
    if(flag == 1 && flag1 == 0) printf("ling ");
    if(num / 100 % 10) {
        if(flag1 == 1) printf(" ");
        printf("%s %s", t[num / 100 % 10], c[1]);
        flag2 = 1;
    }
    if(flag1 == 1 && flag2 == 0 && num % 100 != 0)
        printf(" ling");
    if(num / 10 % 10) {
        if(flag1 == 1 || flag2 == 1) printf(" ");
        printf("%s %s", t[num / 10 % 10], c[0]);
        flag3 = 1;
    }
    if(flag2 == 1 && flag3 == 0 && num % 10 != 0)
        printf(" ling");
    if(num % 10) {
        if(flag1 == 1 || flag2 == 1 || flag3 == 1) printf(" ");
        printf("%s", t[num % 10]);
    }
    
}
int main() {
    int flag1 = 0, flag2 = 0;
    scanf("%d", &a);
    if(a < 0) {
        printf("Fu ");
        a = 0 - a;
    }
    if(a == 0) printf("ling");
    if(a > 99999999) {
        int temp = a / 100000000;
        read(temp);
        printf(" %s", c[4]);
        a = a % 100000000;
        flag1 = 1;
    }
    if(a > 9999) {
        int temp = a / 10000;
        if(flag1 == 1) {
            printf(" ");
            flag = 1;
        }
        read(temp);
        printf(" %s", c[3]);
        a = a % 10000;
        flag2 = 1;
    }
    flag = 0;
    if((flag1 == 1 || flag2 == 1) && a != 0) {
        flag = 1;
        printf(" ");
    }
    read(a);
    return 0;
}
