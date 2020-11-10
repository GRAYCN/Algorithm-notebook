/*--------------------------v1-------------------------------------*/
#include<iostream>
#include<vector>
#include<math.h>

const int SIZE = 1000000;

//## What's the difference between possible and val?
bool possible[SIZE];        // Has the value existed before?
bool val[SIZE];
bool flag[11];
using namespace std;
vector<vector<int> >V;
int main() {
    int N, M, v1, v2;
    scanf("%d%d%d%d", &v1, &v2,&N,&M);
    possible[abs(v1 - v2)] = true;              // Store the difference of the previous value.
    val[v1] = true;
    val[v2] = true;
    V.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        V[i].resize(M + 1);
        for (int j = 1; j <= M; j++) {
            scanf("%d", &V[i][j]);
        }
    }
    vector<int>ex;
    ex.push_back(v1);
    ex.push_back(v2);
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (flag[j] == true)continue;
            int round = i, player = j, num = V[j][i];
            if (val[num] || !possible[num]) {           // not satisfied.
                flag[player] = true;//跳过
                printf("Round #%d: %d is out.\n", round, player);
            }
            else {
                val[num] = true;
                for (int i = 0; i < ex.size(); i++) {
                    possible[abs(num - ex[i])] = true;      // update the difference result to possible.
                }
                ex.push_back(num);
            }
        }
    }

    vector<int>winner;
    for (int i = 1; i <= N; i++) {
        if (!flag[i])winner.push_back(i);
    }
    if (winner.size() > 0) {
        printf("Winner(s):");
        for (int i = 0; i < winner.size(); i++)printf(" %d", winner[i]);
    }
    else printf("No winner.");
    printf("\n");
    return 0;
}


/*----------------v2--------------------*/

//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int maxn = 1010;
//int x, y, n, m;
//vector<int> M[15];
//int flag[15]; //是否出局
//vector<int> exist;
//int maxi = 0;
//int mp[100100];
//bool judge(int v){ //是否符合条件
//    int i, j, k, sz = exist.size();
//    if(mp[v]) return false;
//    for(i=0;i<sz;++i){
//        int e = exist[i];
//        if(e + v > 100000) continue;
//        if(mp[e+v]){
//            break;
//        }
//    }
//    return i < sz;
//}
//
//void solve(){
//    int i, k;
//    exist.push_back(x);
//    exist.push_back(y);
//    maxi = max(x, y);
//    mp[x] = 1;
//    mp[y] = 1;
//    for(k=0;k<m;++k){ //m轮回合
//        for(i=1;i<=n;++i){ //第i个人
//            if(!flag[i]){ //未出局
//                if(judge(M[i][k])){
//                    exist.push_back(M[i][k]);
//                    mp[M[i][k]] = 1;
//                }else{
//                    flag[i] = k + 1;
//                }
//            }
//        }
//    }
//}
//int main(){
//    int i, j, t;
//    ios::sync_with_stdio(false);
//    cin>>x>>y>>n>>m;
//    for(i=1;i<=n;++i){
//        for(j=1;j<=m;++j){
//            cin>>t;
//            M[i].push_back(t);
//        }
//    }
//    solve();
//
//    for(i=1;i<=m;++i){              // i stands for the round num.
//        vector<int> out;
//        for(j=1;j<=n;++j){
//            if(flag[j] == i){
//                out.push_back(j);           //## What's the meaning?
//            }
//        }
//        if(out.empty()) continue;
//        int sz = out.size();
//        for(j=0;j<sz;++j)
//            cout << "Round #" << i << ": " << out[j] << " is out.\n";
//    }
//    vector<int> winners;
//    for(i=1;i<=n;++i){
//        if(!flag[i]) winners.push_back(i);
//    }
//    if(winners.empty()){
//        cout<<"No winner.";
//    }else{
//        cout<<"Winner(s): ";
//        cout << winners[0];
//        for(j=1; j < winners.size(); ++j) cout << ' ' << winners[j];
//    }
//    return 0;
//}
