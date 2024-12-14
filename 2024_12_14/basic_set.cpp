#include <iostream>

#include <unordered_set>
#include <set>

using namespace std;

int main() {
    unordered_set<double> unordered = {1, 2.0, 3.4};
    unordered.insert(-5.5);
    unordered.erase(1);
    unordered.erase(1.2);

    for (auto val: unordered) {
        cout << val << ", ";
    }
    cout << '\n';

    double val = 2;
    // find返回迭代器，直到容器结尾
    if (unordered.find(val) != unordered.end()) cout << "val exists\n";
    else cout << "val does not exist\n";


    return 0;
}