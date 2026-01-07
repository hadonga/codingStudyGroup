#include <thread>
#include <iostream>

void print(const std::string &s) {
    std::cout << "thread " << std::this_thread::get_id() << ": " << s << '\n';
}

int main() {
    std::thread thr1(print, std::string("hahaha"));

    // case 1
    thr1.join();

    // case 2
    // if (thr1.joinable()) thr1.join();
    return 0;
}