#include <thread>
#include <iostream>
#include <functional> // std::bind

void add(double a, double b, double &res) {
    auto id = std::this_thread::get_id();
    
    // std::cout << "thread " << std::this_thread::get_id() << ": enter\n";
    // res_ = a - b;
    // std::cout << "thread " << std::this_thread::get_id() << ": leave\n";
    
    printf("thread %i [add]: enter\n", id);
    res = a + b;
    printf("thread %i [add]: leave\n", id);
}

class cls {
public:
    void add(double a, double b) {
        auto id = std::this_thread::get_id();
        printf("thread %i [cls::add]: enter\n", id);
        res_ = a + b;
        printf("thread %i [cls::add]: leave\n", id);
    }

    double res_ = 0;
};

int main() {
    std::cout << "main thread id: " << std::this_thread::get_id() << '\n';
    double a = 1, b = 2.1, res = -1;

    std::thread thr1(add, a, b, std::ref(res));

    cls obj;
    // std::thread thr2(cls::add, &obj, a, b);
    std::thread thr2(std::bind(&cls::add, &obj, a, b));
    
    double res2 = -1;
    auto add2 = [&res2](double a, double b) {
        auto id = std::this_thread::get_id();
        printf("thread %i [add2]: enter\n", id);
        res2 = a + b;
        printf("thread %i [add2]: leave\n", id);
    };
    std::thread thr3(add2, a, b);

    thr1.join();
    thr2.join();
    thr3.join();

    std::cout << "thr1 result: " << res << '\n';
    std::cout << "thr2 result: " << obj.res_ << '\n';
    std::cout << "thr3 result: " << res2 << '\n';

    return 0;
}