//
// Created by w on 2020/11/13.
//

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int level;
    int value;
}node[110];

//bool cmp(Node a, Node b){
//    if(a.level!=b.level) return a.level<b.level;
//    else return a.value > b.value;
//}

class cmp{
public:
    bool operator()(Node a, Node b){
        if(a.level!=b.level) return a.level > b.level;
        else return a.value > b.value;
    }
};

int N,M;
int main(){
    cin>>N>>M;
    for(int i = 0; i < N; i++){
        cin>>node[i].value;
        node[i].level=0;
    }

    vector<Node> v(M);
    priority_queue<Node, vector<Node>, cmp> pq;
//    priority_queue<Node, vector<Node>, cmp> pq;
    for (int i = 0; i < M; ++i) {
        pq.push(node[i]);
    }
    vector<Node> res;

    int index = M;
    while (!pq.empty()){
        Node tmp = pq.top();
        pq.pop();
        res.push_back(tmp);

        if(index<N) {
            if(node[index].value <= tmp.value) {
                node[index].level = tmp.level+1;
            } else
                node[index].level = tmp.level;

            pq.push(node[index++]);
        }
    }

    for (int i = 0; i < res.size(); ++i) {
        if(i>0 && res[i].level!=res[i-1].level) {
            printf("\n");
        }
        printf("%d ",res[i].value);
    }
}


/*-----------------------------------------------------------*/

#include <cstdio>
#include <queue>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int main5() {

    int N, M;
    scanf("%d%d", &N, &M);

    vector<int> arr(N);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

    priority_queue<int, vector<int>, greater<int>> q;//模拟内存的排序，从小到大排列
    vector<int> nextRound,thisRound;//v存放下轮的数；line存放本轮的数

    int index = 0,count=0, last;
    for (; index < M; index++) q.push(arr[index]);

    while (count != N) {                     //如果从队列里出来的数小于N
        last = q.top();
        thisRound.push_back(last); //根据有序性，每次列头的数会决定arr的下一个数去哪
        q.pop();
        count++;

        if (index < N) {//如果arr里还有数未处理
            if (arr[index] > last) q.push(arr[index++]);
            else nextRound.push_back(arr[index++]);
        }

        if (q.empty()) {//当本轮的数已处理结束，即q为空
            for (int i = 0; i < thisRound.size(); i++) {//输出line
                if (i != 0) printf(" ");
                printf("%d", thisRound[i]);
            }
            printf("\n");
            thisRound.clear();
            for (int i : nextRound)//v的数全都放到q里
                q.push(i);
            nextRound.clear();
        }

    }
}

int main1(){
    int N, M;
    scanf("%d%d", &N, &M);
    vector<int> arr(N);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

    priority_queue<int, vector<int>,greater<int>> q;
    vector<int> v,line;//v存放下轮的数；line存放本轮的数

    int index = 0, count =0, last;
    for (; index < M; index++) q.push(arr[index]);

    while (count != N) {
        last = q.top();
        line.push_back(last);//根据有序性，每次列头的数会决定arr的下一个数去哪
        q.pop();
        count++;

        if (index < N) {
            if (arr[index] > last) {
                q.push(arr[index++]);
            } else v.push_back(arr[index++]);
        }

        if (q.empty()) {
            for (int i = 0; i < line.size(); i++) {//输出line
                if (i != 0) printf(" ");
                printf("%d", line[i]);
            }
            printf("\n");

            line.clear();
            for (int i:v) {
                q.push(i);
            }
            v.clear();
        }
    }
}

int main2(){
    int N, M, val;
    scanf("%d%d", &N, &M);
    map<int, int>Ma, Mb;
    for (int i = 0; i < M; i++) {
        scanf("%d", &val);
        Ma[val]++;
    }
    vector<int>tmp;
    vector<vector<int>>ans;
    for (int i = M; i < N; i++) {
        scanf("%d", &val);
        int head = Ma.begin()->first;
        if(Ma.begin()->second==1)Ma.erase(Ma.begin());
        else Ma[Ma.begin()->first]--;
        tmp.push_back(head);
        if (val >= head)Ma[val]++;//Ma存放本轮
        else Mb[val]++;//Mb存放下一轮
        if (Ma.size() == 0) {//本轮的数都处理好了
            Ma = Mb;
            Mb.clear();
            ans.push_back(tmp);//将本轮的解tmp汇总到ans
            tmp.clear();
        }
        if (i == N - 1) {//到了最后一个数，要将Ma和Mb分别存到解中
            while (Ma.size()) {
                tmp.push_back(Ma.begin()->first);
                if(Ma.begin()->second==1) Ma.erase(Ma.begin());
                else Ma[Ma.begin()->first]--;
            }
            if (tmp.size() > 0)ans.push_back(tmp);
            tmp.clear();
            while (Mb.size()) {
                tmp.push_back(Mb.begin()->first);
                if (Mb.begin()->second == 1) Mb.erase(Mb.begin());
                else Mb[Mb.begin()->first]--;
            }
            ans.push_back(tmp);
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            if (j == 0)printf("%d", ans[i][j]);
            else printf(" %d", ans[i][j]);
            if (j == ans[i].size() - 1)printf("\n");
        }
    }
    return 0;
}

int main3(){
    int N, M;
    scanf("%d%d", &N, &M);
    vector<int> arr(N);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

//    priority_queue<int, vector<int>, greater<int>> q;//模拟内存的排序，从小到大排列
    set<int> s;
    vector<int> v,line;//v存放下轮的数；line存放本轮的数
    int index = 0,count=0, last;
    for (; index < M; index++) s.insert(arr[index]);

    while (count != N) {//如果从队列里出来的数小于N
        last = *s.begin();
        line.push_back(last);
        s.erase(s.begin());
        count++;
        if (index < N) {
            if(arr[index] > last) s.insert(arr[index++]);
            else v.push_back(arr[index++]);
        }

        if (s.empty()) {
            for (int i = 0; i < line.size(); i++) {//输出line
                if (i != 0) printf(" ");
                printf("%d", line[i]);
            }
            printf("\n");
            line.clear();
            for (int i = 0; i < v.size(); i++)//v的数全都放到q里
                s.insert(v[i]);
            v.clear();
        }
    }
}