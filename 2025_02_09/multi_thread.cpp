#include<iostream>
#include<thread>

using namespace std;

void hello(){
    cout << "Thred ID:" << this_thread::get_id() << '\n';
}

int main(){
    thread t1(hello);
    thread t2(hello);
    t1.join();
    t2.join();
    return 0;
}