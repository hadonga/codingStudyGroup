#include <iostream>

// using namespace std;

namespace hd {

class test {
public:
    test() {
        val_ = 1;
        val_private_ = 10 * val_;
    }

    test(int val) {
        val_ = val;
        val_private_ = 10 * val_;
    }

    int val_;

private:
    int val_private_;
};

} // namespace hd


int main() {
    hd::test my_test1;
    std::cout << "val_: " << my_test1.val_ << '\n';

    hd::test my_test2(1000);
    std::cout << "val_: " << my_test2.val_ << '\n';
    // cout << my_test2.val_private_ << '\n';

    return 0;
}