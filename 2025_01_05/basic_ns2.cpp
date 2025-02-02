#include </home/hd/codingStudyGroup/2025_01_05/basic_ns2.hpp>

namespace hd {

Test::Test() {
    val_ = 5;
}

Test::Test(int val) {
    SetVal(val);
}

int Test::GetVal() {
    return val_;
}

void Test::SetVal(int val) {
    val_ = val;
}


namespace hdhd {

int sum(int a, int b) {
    return a + b;
}

} // namespace hdhd
} // namespace hd

int main() {
    hd::Test my_test;
    std::cout << "val_: " << my_test.GetVal() << '\n';

    my_test.SetVal(10);
    std::cout << "val_: " << my_test.GetVal() << '\n';

    int a = 1, b = 2;
    std::cout << "a + b: " << hd::hdhd::sum(a, b) << '\n';

    return 0;
}