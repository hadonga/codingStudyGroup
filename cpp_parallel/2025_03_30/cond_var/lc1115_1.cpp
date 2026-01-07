#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <functional>

class FooBar {
private:
    int n;
    std::mutex mutex_;
    std::condition_variable cond_var_;
    bool done_foo_ {false};

public:
    /**
     * @brief Constructor for FooBar class
     * @param n The number of times to print "foo" and "bar" alternately
     * @details Initializes a FooBar instance with the specified count
     */<think>
    FooBar(int n) {
        this->n = n;
    }

    void foo() {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mutex_);
            cond_var_.wait(lock, [&](){ return !done_foo_; });
            
        	printf("foo");

            done_foo_ = true;
            lock.unlock();
            cond_var_.notify_one();
        }
    }

    void bar() {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mutex_);
            cond_var_.wait(lock, [&](){ return done_foo_; });
            
        	printf("bar\n");

            done_foo_ = false;
            lock.unlock();
            cond_var_.notify_one();
        }
    }
};

int main() {
    FooBar obj(4);
    std::thread t1(std::bind(&FooBar::foo, &obj));
    std::thread t2(std::bind(&FooBar::bar, &obj));
    t1.join();
    t2.join();
    return 0;
}