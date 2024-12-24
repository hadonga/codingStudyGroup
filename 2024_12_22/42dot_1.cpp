#include <iostream>

#include <vector>

using namespace std;

int main() {
    vector<int> a = {1,2,3};
    vector<int> b = a;
    a[0] = 10;
    for (auto val: b) cout << val << ", ";
    cout << '\n';

    int i0 = 1, i1 = 2;
    cout << "i0 ^ i1 = " << (i0 ^ i1) << '\n';
    return 0;
}