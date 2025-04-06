#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <functional>
#include <vector>

class FooBar {
private:
    int n;
    std::mutex mutex_;
    std::condition_variable cond_var_;
    bool foo_done_ = false;
    bool bar_done_ = false;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo() {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mutex_);

        	// printFoo() outputs "foo". Do not change or remove this line.
        	std::cout << "foo";
            foo_done_ = true;
            cond_var_.notify_one();
            while (!bar_done_){
                cond_var_.wait(lock);
            }
            bar_done_ = false;
        }
    }

    void bar() {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mutex_);
            while(!foo_done_){
                cond_var_.wait(lock);
            }
            foo_done_ = false;
        	// printBar() outputs "bar". Do not change or remove this line.
        	std::cout << "bar" << std::endl;;
            bar_done_ = true;
            cond_var_.notify_one();
        }
    }
};

int main(){
    FooBar fb(10);
    std::thread t1(std::bind(&FooBar::foo, &fb));
    std::thread t2(std::bind(&FooBar::bar, &fb));

    t1.join();
    t2.join();

    return 0;

}