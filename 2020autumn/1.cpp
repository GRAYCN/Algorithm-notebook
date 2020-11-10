//
// Created by w on 2020/11/10.
//


#include <bits/stdc++.h>

using namespace std;
/**
 * 题意：熊猫喝奶
 * 思路：从左往右扫描一遍，设node[0].milk=200，对于i<j，若node[j].weight>node[i].weight，则node[j].milk=node[i].milk+100，若相等，则node[j].milk=node[i].milk
 * 若小于，则重新赋为200。这样就保证了所有熊猫都不会与左边的熊猫打架
 * 而再从右往左扫描一遍，同理保证了所有熊猫不会与右边的熊猫打架，取两次序列中较大的值作为最终的奶量即可。
 * @return
 */
const int N = 1e4 + 10;
struct Node {
    int weight;//weight为体重
    int milk;//milk为分配的牛奶
} node[N];
vector<int> LtoR, RtoL;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int weight;
        cin >> weight;
        node[i].weight = weight;
    }
    //从左到右扫描
    node[0].milk = 200;
    LtoR.push_back(node[0].milk);
    for (int i = 1; i < n; ++i) {
        if (node[i].weight > node[i - 1].weight)node[i].milk = node[i - 1].milk + 100;
        else if (node[i].weight == node[i - 1].weight)node[i].milk = node[i - 1].milk;
        else node[i].milk = 200;
        LtoR.push_back(node[i].milk);
    }
    //从右到左扫描
    node[n - 1].milk = 200;
    RtoL.push_back(node[n - 1].milk);
    for (int i = n - 2; i >= 0; i--) {
        if (node[i].weight > node[i + 1].weight)node[i].milk = node[i + 1].milk + 100;
        else if (node[i].weight == node[i + 1].weight)node[i].milk = node[i + 1].milk;
        else node[i].milk = 200;
        RtoL.push_back(node[i].milk);
    }
    reverse(RtoL.begin(), RtoL.end());
    int sum = 0, temp;
    for (int i = 0; i < n; ++i) {
        temp = max(LtoR[i], RtoL[i]);
        sum += temp;
    }
    cout << sum << endl;
    return 0;
}