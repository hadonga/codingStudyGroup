#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <functional>

class ZeroEvenOdd {
private:
    int n;
    std::mutex mutex_;
    std::condition_variable cond_var_;
    int flag_ {0};

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero() {
        for (int i = 0; i < n; ++i) {
            std::unique_lock<std::mutex> lock(mutex_);
            cond_var_.wait(lock, [&](){ return flag_ == 0; });
            printf("0");
            if (i % 2 == 0) flag_ = 1;
            else flag_ = 2;
            // lock.unlock();
            cond_var_.notify_all();
        }
    }

    void even() {
        for (int i = 2; i <= n; i+=2) {
            std::unique_lock<std::mutex> lock(mutex_);
            cond_var_.wait(lock, [&](){ return flag_ == 2; });
            printf("%i", i);
            flag_ = 0;
            // lock.unlock();
            cond_var_.notify_all();
        }
    }

    void odd() {
        for (int i = 1; i <= n; i+=2) {
            std::unique_lock<std::mutex> lock(mutex_);
            cond_var_.wait(lock, [&](){ return flag_ == 1; });
            printf("%i", i);
            flag_ = 0;
            // lock.unlock();
            cond_var_.notify_all();
        }
    }
};


int main() {
    ZeroEvenOdd obj(6);
    std::thread t1(std::bind(&ZeroEvenOdd::zero, &obj));
    std::thread t2(std::bind(&ZeroEvenOdd::even, &obj));
    std::thread t3(std::bind(&ZeroEvenOdd::odd, &obj));
    t1.join();
    t2.join();
    t3.join();
    std::cout << '\n';
    return 0;
}