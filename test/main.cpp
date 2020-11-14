#include <iostream>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int,vector<int>, greater<>> pqueue;
    pqueue.push(0);
    pqueue.push(1);
    pqueue.push(2);

    while (!pqueue.empty()) {
        cout << ' ' << pqueue.top();
        pqueue.pop();
    }



    return 0;
}
