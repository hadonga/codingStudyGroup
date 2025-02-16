#include <thread>
#include <future>
#include <iostream>
#include <functional>

class Foo {
public:

    Foo() {}

    void first() {
        printf("first, ");
        done_first_.set_value();
    }

    void second() {
        done_first_.get_future().get();
        printf("second, ");
        done_second_.set_value();
    }

    void third() {
        done_second_.get_future().get();
        printf("third\n");
    }

private:

    std::promise<void> done_first_, done_second_;
};

int main() {
    Foo foo;
    std::thread first(std::bind(&Foo::first, &foo));
    std::thread second(std::bind(&Foo::second, &foo));
    std::thread third(std::bind(&Foo::third, &foo));
    first.join();
    second.join();
    third.join();
    
    return 0;
}