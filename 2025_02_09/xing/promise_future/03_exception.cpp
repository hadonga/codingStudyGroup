#include <future>
#include <iostream>

// lvalue reference is also fine
void divide(double a, double b, std::promise<double> &&promise) {
    try {
        if (b == 0) {
            throw std::runtime_error("denominator is 0");
        }
        promise.set_value(a / b);
    }
    catch(...) {
        promise.set_exception(std::current_exception());
    }
}

int main() {
    std::promise<double> promise;
    auto future = promise.get_future();

    double a = 1, b = 0;

    std::thread th(divide, a, b, std::move(promise));
    try {
        auto res = future.get();
        std::cout << "a / b = " << res << '\n';
    }
    catch (std::runtime_error &e) {
        std::cout << e.what() << '\n';
    }

    th.join();

    return 0;
}