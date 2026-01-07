#include <iostream>
#include <thread>

void print1(std::string &msg) {
    std::cout << msg;
    // printf(msg.c_str());
}

void print2(std::string &&msg) {
    std::cout << msg;
    // printf(msg.c_str());
}

int main() {
    std::string msg1 = "hello1\n";
    std::string msg2 = "hello2\n";
    // std::string msg3 = "hello3";
    std::thread t1(print1, std::ref(msg1)); // not copy msg
    std::thread t2(print2, std::move(msg2)); // not copy msg
    std::thread t3(print2, std::move("hello3\n")); // not copy msg
    t1.join();
    t2.join();
    t3.join();

    {
        // will throw errors
        // print1("haha\n");

        // ok
        std::string ha = "haha\n";
        print1(ha);
    }
    
    return 0;
}