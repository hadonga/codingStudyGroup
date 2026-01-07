#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>
#include <functional>

class Counter {
public:
    void add_n(int n) {
        for (int i = 0; i < n; ++i) {
            mutex_cnt_.lock();
            cnt_ += 1;
            mutex_cnt_.unlock();
        }
    }
    int get() {
        int res = 0;
        mutex_cnt_.lock();
        res = cnt_;
        mutex_cnt_.unlock();
        return res;
    }

    // Wrong! unlock() is not invoked!
    // int get_wrong() {
    //     mutex_cnt_.lock();
    //     return cnt_;
    // }

    int cnt_ {0};
    std::mutex mutex_cnt_;
};

int main() {
    int n1 = 1.5e5, n2 = 2.5e5;
    Counter counter;

    auto time1 = std::chrono::high_resolution_clock::now();

    std::thread t1(std::bind(&Counter::add_n, &counter, n1));
    std::thread t2(std::bind(&Counter::add_n, &counter, n2));
    t1.join();
    t2.join();

    auto time2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = time2 - time1;
    std::cout << "elapsed time: " << elapsed.count() << "s\n";

    std::cout << "cnt: " << counter.get() << '\n';

    return 0;
}