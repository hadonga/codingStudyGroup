#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    priority_queue<int> pq_big;
    pq_big.push(1);
    pq_big.push(2);
    pq_big.push(4);
    pq_big.push(3);
    pq_big.push(3);
    while (!pq_big.empty()) {
        cout << "size: " << pq_big.size() << '\n';
        cout << pq_big.top() << '\n';
        pq_big.pop();
    }
    cout << "=============================\n";

    priority_queue<int, vector<int>, greater<int>> pq_small;
    pq_small.push(1);
    pq_small.push(2);
    pq_small.push(4);
    pq_small.push(3);
    pq_small.push(3);
    while (!pq_small.empty()) {
        cout << "size: " << pq_small.size() << '\n';
        cout << pq_small.top() << '\n';
        pq_small.pop();
    }

    cout << "=============================\n";

    using PID = pair<int, double>;
    priority_queue<PID> pq_pid;
    pq_pid.push(make_pair(1, 2));
    pq_pid.push(make_pair(2, 1));
    pq_pid.push(make_pair(3, 2.2));
    pq_pid.push(make_pair(3, 2.5));
    while (!pq_pid.empty()) {
        cout << "size: " << pq_pid.size() << '\n';
        cout << pq_pid.top().first << ", " << pq_pid.top().second << '\n';
        pq_pid.pop();
    }


    return 0;
}