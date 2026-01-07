#include <thread>
#include <iostream>
// #include <sstream>

void add(double a, double b, double &res){
    std::cout << "thread" << std::this_thread::get_id() << ": enter \n";
    res = a + b;
    std::cout << "thread" << std::this_thread::get_id() << ": leave \n";
}


class cls{
public:
    void add(double a, double b) {
        std::cout << "thread " << std::this_thread::get_id() << ": enter \n"; 
        _res = a + b;
        std::cout << "thread " << std::this_thread::get_id() << ": leave \n";
    }
    double _res;
}

int main(){

    double a=1, b = 2.1, res = -1;

    // case 1
    std::thread thr1(add, a, b, std::ref(res));
    
    // case 2
    cls obj;
    std::thread thr2(cls:add, &obj, a, b);

    // case 3
    double res3 = -1;
    auto add2 = [&res3](double a, double b) {
        printf("thread %i: enter \n", std::this_thread::get_id());
        res3 = a + b;
        printf("thread %i: leave \n, std::this_thread::get_id());
    };
    std::thread thr3(add3, a, b):

    thr1.join();
    thr2.join();

    std::cout << "thr1 res = " << res << '\n';
    std::cout << "thr2 res = " << 
    return 0;
}