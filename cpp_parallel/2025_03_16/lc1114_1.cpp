#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <functional>

class Foo {
public:

    Foo() {}

    void first() {
        printf("first, ");
        done_first_ = true;
        cond_var_.notify_all();
    }

    void second() {
        std::unique_lock<std::mutex> lock(mutex_);
        cond_var_.wait(lock, [this]() {return done_first_;});
        printf("second, ");
        done_second_ = true;
        lock.unlock();
        cond_var_.notify_all();
    }

    void third() {
        std::unique_lock<std::mutex> lock(mutex_);
        cond_var_.wait(lock, [this]() {return done_second_;});
        printf("third\n");
    }

private:
    std::mutex mutex_;
    std::condition_variable cond_var_;
    bool done_first_ {false}, done_second_ {false};
};

int main() {
    Foo foo;
    std::thread t1(std::bind(&Foo::first, &foo));
    std::thread t2(std::bind(&Foo::second, &foo));
    std::thread t3(std::bind(&Foo::third, &foo));
    t1.join();
    t2.join();
    t3.join();
    
    return 0;
}