#include <iostream>

#include <memory>
#include <vector>

using namespace std;


int main() {
    vector<int> vec(4,2);
    shared_ptr<vector<int>> vec_ptr = make_shared<vector<int>>(4, 2);
    for (int i = 0; i < vec_ptr->size(); ++i) {
        cout << (*vec_ptr) [i] << ", ";
    }
    cout << '\n';
    cout << vec_ptr->back() << '\n';

    return 0;
}