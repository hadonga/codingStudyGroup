#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <functional>

class Foo {
public:
    void first() {
        // std::unique_lock<std::mutex> lock(mutex_);
        std::cout << "first" << std::endl;
        done_first_ = true;
        // lock.unlock();
        cond_var_.notify_all();
    }

    void second() {
        std::unique_lock<std::mutex> lock(mutex_);
        while (!done_first_){
            cond_var_.wait(lock);
        }
        std::cout << "second" << std::endl;
        done_second_ = true;
        lock.unlock();
        cond_var_.notify_all();
    }

    /**
     * @brief Executes the third task in sequence after the second task is completed.
     * 
     * This method waits for the second task to complete using condition variable synchronization,
     * then prints "third" to standard output. It uses mutex locking to ensure thread safety.
     * 
     * @note This function blocks until the second task signals completion.
     */<think>
    void third() {
        std::unique_lock<std::mutex> lock(mutex_);
        while (!done_second_){
            cond_var_.wait(lock);
        }
        std::cout << "third" << std::endl;
        // done_third_ = true;
        // lock.unlock();
        // cond_var_.notify_all();
    }

private:
    bool done_first_ = false;
    bool done_second_ = false;
    // bool done_third_ = false;

    std::mutex mutex_;
    std::condition_variable cond_var_;
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