#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <functional>


class ZeroEvenOdd {
private:
    int n;
    int flag {0};
    std::mutex mutex_;
    std::condition_variable cond_var_;  

public:
    ZeroEvenOdd(int n) {
        this->n = n;

    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero() {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mutex_);
            while(flag!=0){
                cond_var_.wait(lock);
            }
            std::cout << 0;
            if (i%2 == 0){
                flag = 1;
            }
            else{
                flag = 2;
            }            
            cond_var_.notify_all();
        }
    }

    void even() {
        for (int i = 2; i <= n; i+=2) {
            std::unique_lock<std::mutex> lock(mutex_);
            while(flag!=2){
                cond_var_.wait(lock);
            }
            std::cout << i;
            flag = 0;
            cond_var_.notify_all();
        }
    }
    void odd() {
        for (int i = 1; i <= n; i+=2) {
            std::unique_lock<std::mutex> lock(mutex_);
            while(flag!=1){
                cond_var_.wait(lock);
            }
            std::cout << i;
            flag = 0;
            cond_var_.notify_all();
        }
    }
};

int main(){
    int n = 15;
    ZeroEvenOdd obj(n);
    std::thread t1(std::bind(&ZeroEvenOdd::zero, &obj));
    std::thread t2(std::bind(&ZeroEvenOdd::odd, &obj));
    std::thread t3(std::bind(&ZeroEvenOdd::even, &obj));
    t1.join();
    t2.join();
    t3.join();
    std::cout << '\n';
    return  0;

}   