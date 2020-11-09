//PATA1034
#include<iostream>
#include<algorithm>
#include<string>
#include<map>

using namespace std;
#define maxn 2005
#define inf 10000000000
map<int, string> intToString;
map<string, int> stringToInt;
map<string, int> Gang;
int edge[maxn][maxn];
int weight[maxn];
bool vis[maxn];

int n, k;
int numPerson;
// change the name(string) to corresponding id(int)
int change(string str) {
    if (stringToInt.find(str) != stringToInt.end()) {
        return stringToInt[str];
    } else {
        stringToInt[str] = numPerson;
        intToString[numPerson] = str;
        return numPerson++;
    }

}

int numGang;
int head;
int maxTime = -1;
int totalTime = 0;
void DFS(int nowVisit) {
    vis[nowVisit] = true;
    numGang++;
    if (weight[nowVisit] > maxTime) {
        maxTime = weight[nowVisit];
        head = nowVisit;
    }

    for (int i = 0; i < numPerson; i++) {
        if (edge[nowVisit][i] > 0) {
            totalTime += edge[nowVisit][i];
            edge[nowVisit][i] = edge[i][nowVisit] = 0;
            if (vis[i] == false)
                DFS(i);
        }
    }
}

void DFSTrave() {
    for (int i = 0; i < numPerson; i++) {
        if (vis[i] == false) {
            numGang = 0;
            head = i;
            totalTime = 0;
            maxTime = -1;
            DFS(i);
            if (numGang > 2 && totalTime > k) {
                Gang[intToString[head]] = numGang;
            }
        }
    }
}

int main() {
    cin >> n >> k;
    string a, b;
    int time;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> time;
        int id1 = change(a);
        int id2 = change(b);
        weight[id1] += time;
        weight[id2] += time;
        edge[id1][id2] += time;
        edge[id2][id1] += time;
    }
    DFSTrave();
    cout << Gang.size() << endl;
    for (auto it = Gang.begin(); it != Gang.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}


