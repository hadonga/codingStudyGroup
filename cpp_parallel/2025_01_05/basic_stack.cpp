#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> stk;
    stk.push(10);
    stk.push(100);
    while (!stk.empty()) {
        cout << "stk size: " << stk.size() << '\n';
        cout << stk.top() << '\n';
        stk.pop();
    }

    return 0;
}