#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main(){
    int N,M;
    int cnt = 0;
    scanf("%d%d",&N,&M);
    vector<int> v(N), sum(N+1,0);
    for(int i=0;i<N;i++){
        scanf("%d",&v[i]);
        sum[i+1]=sum[i]+v[i];
    }

    for(int i=-1;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(sum[j+1]-sum[i+1] <= M) cnt++;
        }
    }

    printf("%d\n", cnt);
    return 0;
}