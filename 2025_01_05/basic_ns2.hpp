#include <iostream>

namespace hd {

class Test {
public:
    Test();
    Test(int val);

    int GetVal();
    void SetVal(int val);

private:
    int val_;
};

namespace hdhd {

int sum(int a, int b);

} // namespace hdhd

} // namespace hd