#include <vector>
#include <iostream>

class MyClass {
public:

    MyClass() {
        vec_ = std::vector<int>(3, 2);
    }

    ~MyClass() {};

    std::vector<int> vec_;
};

int main() {
    MyClass obj;

    for (auto val: obj.vec_) {
        std::cout << val << ", ";
    }
    std::cout << '\n';

    std::vector<int> vec1;
    std::vector<int> vec2(4, 2);

    return 0;
}