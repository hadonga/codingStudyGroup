#include <thread>
#include <future>
#include <iostream>
#include <functional>

class ZeroEvenOdd{
private:
    int n;
    std::promise<void> start_even_, start_odd_, start_zero_;
public:
    ZeroEvenOdd(int n) {
            this->n = n;
        }

    void zero(){
        for (int i = 0; i < n; ++i){
            std::cout << "0";
            if (i%2) start_even_.set_value();
            else start_odd_.set_value();
            start_zero_.get_future().get();
            start_zero_ = std::promise<void>();
        }
    }
    void even(){
        for (int i = 2; i < n; i+=2){
            start_even_.get_future().get();
            start_even_ = std::promise<void>();
            std::cout << i;
            start_zero_.set_value();
        }
    }
    void odd(){
        for (int i = 1; i < n; i+=2){
            start_odd_.get_future().get();
            start_odd_ = std::promise<void>();
            std::cout << i;
            start_zero_.set_value();
        }
    }
    void printNumber(int i){
        printf("%i", i);
    }
};

int main(){
    int n = 10;
    ZeroEvenOdd obj(n);
    std::thread t1(std::bind(&ZeroEvenOdd::zero, &obj));
    std::thread t2(std::bind(&ZeroEvenOdd::odd, &obj));
    std::thread t3(std::bind(&ZeroEvenOdd::even, &obj));

    t1.join();
    t2.join();
    t3.join();

    std::cout << '\n';
    
    return 0;
}