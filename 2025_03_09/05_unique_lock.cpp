#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>

class Counter {
public:
    void add_n(int n) {
        int cnt = 0;
        int add_per_cnt = 1e5;
        // The std::mutex object is not immediately locked with the
        // std:defer_lock option.
        std::unique_lock<std::mutex> lock(mutex_cnt_, std::defer_lock);
        for (int i = 0; i < n; ++i) {
            cnt += 1;
            if (cnt >= add_per_cnt) {
                lock.lock();
                
                std::cout << "thread " << std::this_thread::get_id() << ": lock\n";
                cnt_ += cnt;
                cnt = 0;
                std::cout << "thread " << std::this_thread::get_id() << ": unlock\n";

                lock.unlock();
            }
        }
        if (cnt != 0) {
            lock.lock();
            cnt_ += cnt;
            // lock.unlock(); // not necessary
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
    
    std::thread t1(Counter::add_n, &counter, n1);
    std::thread t2(Counter::add_n, &counter, n2);
    t1.join();
    t2.join();

    auto time2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = time2 - time1;
    std::cout << "elapsed time: " << elapsed.count() << "s\n";

    std::cout << "cnt: " << counter.get() << '\n';

    return 0;
}