// 1. 获取和释放可以由不同线程完成。
// 2. g++ -std=c++20 file.cpp

#include <string>
#include <array>
#include <thread>
#include <mutex>
#include <semaphore>
#include <chrono>
#include <sstream>
#include <iostream>

template<int N>
class ParkingLot {
public:
    ParkingLot(): sem_(N) {}

    int Enter() {
        auto tid = std::this_thread::get_id();
        std::unique_lock<std::mutex> lock(mutex_);
        std::cout << "[Thread " << tid << "] Gonna enter the lot" << std::endl;
        lock.unlock();

        sem_.acquire();
        
        lock.lock();
        for (int i = 0; i < N; ++i) {
            if (places_[i].empty()) {
                std::ostringstream s;
                s << tid;
                places_[i] = s.str();
                std::cout << "[Thread " << tid << "] Park at " << i << std::endl;
                return i;
            }
        }
        throw(std::runtime_error("Exception!"));
    }

    void Stay() {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    void Leave(int i) {
        auto tid = std::this_thread::get_id();
        {
            std::unique_lock<std::mutex> lock(mutex_);
            places_[i].clear();
            std::cout << "[Thread " << tid << "] Leave from " << i << std::endl;
        }
        
        sem_.release();
    }
    
private:
    std::array<std::string, N> places_;
    std::mutex mutex_;
    std::counting_semaphore<N> sem_;
};

int main() {
    const int n_places = 2;
    ParkingLot<n_places> lot;

    auto enter_leave = [&]() {
        int park_place = lot.Enter();
        lot.Stay();
        lot.Leave(park_place);
    };

    const int n_cars = 5;
    std::array<std::thread, n_cars> cars;
    for (int i = 0; i < n_cars; ++i) {
        cars[i] = std::thread(enter_leave);
    }
    for (auto &t: cars) {
        t.join();
    }
    return 0;
}