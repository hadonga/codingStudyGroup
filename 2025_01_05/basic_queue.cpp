#include <iostream>
#include <queue>

// using namespace std;


int main() {
    using PID = std::pair<int, double>;
    std::queue<PID> q;
    q.push(std::make_pair(1, 2));
    // q.push({1,2});

    // PID element = {3, 4.5};
    PID element = std::make_pair(3, 4.5);
    q.push(element);

    while (!q.empty()) {
        std::cout << "q size: " << q.size() << '\n';
        auto e = q.front();
        std::cout << e.first << ", " << e.second << '\n';
        q.pop();
    }

    return 0;
}