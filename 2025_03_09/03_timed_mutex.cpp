#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>

class Counter {
public:
    void add_n_v1(int n) {
        int cnt = 0;
        int add_per_cnt = 1e5;
        for (int i = 0; i < n; ++i) {
            cnt += 1;
            if (cnt >= add_per_cnt) {
                if (mutex_cnt_.try_lock_for(std::chrono::milliseconds(100))) {
                    std::cout << "thread " << std::this_thread::get_id() << ": try_lock success\n";
                    cnt_ += cnt;
                    cnt = 0;
                    mutex_cnt_.unlock();
                }
                else {
                    std::cout << "thread " << std::this_thread::get_id() << ": try_lock fail\n";
                }
            }
        }
        if (cnt != 0) {
            mutex_cnt_.lock();
            cnt_ += cnt;
            mutex_cnt_.unlock();
        }
    }

    void add_n_v2(int n) {
        int cnt = 0;
        int add_per_cnt = 1e5;
        for (int i = 0; i < n; ++i) {
            cnt += 1;
            if (cnt >= add_per_cnt) {
                auto t = std::chrono::steady_clock::now();
                if (mutex_cnt_.try_lock_until(t + std::chrono::milliseconds(100))) {
                    std::cout << "thread " << std::this_thread::get_id() << ": try_lock success\n";
                    cnt_ += cnt;
                    cnt = 0;
                    mutex_cnt_.unlock();
                }
                else {
                    std::cout << "thread " << std::this_thread::get_id() << ": try_lock fail\n";
                }
            }
        }
        if (cnt != 0) {
            mutex_cnt_.lock();
            cnt_ += cnt;
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
    std::timed_mutex mutex_cnt_;
};

int main() {
    int n1 = 1.5e5, n2 = 2.5e5;
    Counter counter;

    auto time1 = std::chrono::high_resolution_clock::now();
    
    std::thread t1(Counter::add_n_v2, &counter, n1);
    std::thread t2(Counter::add_n_v2, &counter, n2);
    t1.join();
    t2.join();

    auto time2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = time2 - time1;
    std::cout << "elapsed time: " << elapsed.count() << "s\n";

    std::cout << "cnt: " << counter.get() << '\n';

    return 0;
}