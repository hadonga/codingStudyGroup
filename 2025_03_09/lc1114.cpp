#include <thread>
#include <iostream>
#include <mutex>
#include <functional>

class Foo{
public:
    Foo() {}
    std::mutex mutex_
    void first(){
        mutex_.lock();
        printf("first");
        mutex_.unlock();
    }

    void second(){
        auto future = done_first.get_future();
        future.get();
        printf("second");
        done_second.set_value();
    }

    void third(){
        auto future = done_second.get_future();
        future.get();

        printf("Third \n");
    }

    std::promise<void> done_first, done_second;

};

int main(){
    Foo foo1;

    std::thread thr1(std::bind(&Foo::first, &foo1));
    std::thread thr2(std::bind(&Foo::second, &foo1));
    std::thread thr3(std::bind(&Foo::third, &foo1));

    thr1.join();
    thr2.join();
    thr3.join();

    return 0;
}