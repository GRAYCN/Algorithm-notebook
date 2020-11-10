//
// Created by w on 2020/11/10.
//


#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1005;
const int MAX_DIS = 500;

struct Edge {
    int v;
    int score, daijinquan;

    Edge() {};

    Edge(int _v, int _score, int _daijinquan) {
        v = _v;
        score = _score;
        daijinquan = _daijinquan;
    }
};

vector<Edge> graph[NMAX];
int in[NMAX], in_buff[NMAX];
int n, m;

//vector<int> pre[NMAX];
int pre[NMAX];

void Dijkstra() {
    bool visited[NMAX];
    int dis_score[NMAX];
    int dis_daijinquan[NMAX];
    fill(visited, visited + NMAX, false);
    fill(dis_score, dis_score + NMAX, MAX_DIS);
    fill(dis_daijinquan, dis_daijinquan + NMAX, 0);
    //dis_score[n]=0;
    //int node;
    for (Edge e:graph[n]) {
        dis_score[e.v] = dis_daijinquan[e.v] = 0;
        pre[e.v] = n;
    }
    while (true) {
        int min_node = n;
        int min_dis = MAX_DIS;
        for (int i = 0; i < n; i++) {
            if (visited[i])
                continue;

            if (dis_score[i] < min_dis) {
                min_dis = dis_score[i];
                min_node = i;
            } else if (dis_score[i] == min_dis) {
                if (dis_daijinquan[i] > dis_daijinquan[min_node])
                    min_node = i;
            }
        }
        if (min_node == n)
            break;
        visited[min_node] = true;
        for (Edge e:graph[min_node]) {
            if (min_dis + e.score < dis_score[e.v]) {
                pre[e.v] = min_node;
                dis_score[e.v] = min_dis + e.score;
                dis_daijinquan[e.v] = dis_daijinquan[min_node] + e.daijinquan;
            } else if (min_dis + e.score == dis_score[e.v]) {
                if (dis_daijinquan[min_node] + e.daijinquan > dis_daijinquan[e.v]) {
                    pre[e.v] = min_node;
                    dis_daijinquan[e.v] = dis_daijinquan[min_node] + e.daijinquan;
                }
            }
        }
    }
}

void consist() {
    // 无环 Dijkstra 算法
    cout << "Okay." << endl;
    Dijkstra();
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int dst;
        cin >> dst;

        if (pre[dst] == n) {
            printf("You may take test %d directly.", dst);
        } else {
            vector<int> path;
            while (dst != n) {
                path.push_back(dst);
                dst = pre[dst];
            }
            int l = path.size();
            printf("%d", path[l - 1]);
            for (int j = l - 2; j >= 0; j--) {
                printf("->%d", path[j]);
            }
            printf("");
        }
    }
}

void not_consist() {
    // 有环，直接判断
    cout << "Impossible." << endl;
    int k;
    cin >> k;
    while (k--) {
        int node;
        cin >> node;
        if (in[node] == 0)
            printf("You may take test %d directly.", node);
        else
            printf("Error.");
    }
}

bool check() {
    // 判断是否有环
    bool visited[NMAX];
    fill(visited, visited + NMAX, false);
    for (int i = 0; i < n; i++) {
        int node = 0;
        for (; node < n; node++) {
            if (!visited[node] && in[node] == 0) {
                break;
            }
        }
        if (node == n)
            break;
        visited[node] = true;
        for (Edge t:graph[node]) {
            in[t.v]--;
        }
    }
    for (int i = 0; i < n; i++) {
        if (in[i])
            return false;
    }
    return true;            // There is no cycle.
}

int main() {

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, s, d;
        cin >> u >> v >> s >> d;
        in[v]++;
        in_buff[v]++;// 入读保存两份，一份用来判环，一份判断是否是启示节点（一开始入读就是0的节点）
        graph[u].push_back(Edge(v, s, d));
    }

    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            // 用节点n作为总起始节点，连接所有起始入度为零的节点，将图变成单源的
            graph[n].push_back(Edge(i, 0, 0));
        }
    }
    if (check())
        consist();
    else
        not_consist();
    return 0;
}