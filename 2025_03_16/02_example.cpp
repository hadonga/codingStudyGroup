#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <iostream>

class DataManager {
public:

    void AddData() {
        auto id = std::this_thread::get_id();
        for (int i = 0; i < 2; ++i) {
            std::unique_lock<std::mutex> lock(mutex_);
            data_.push(i);
            std::cout << "[Thread " << id << "] AddData(): Add " << i << std::endl;
            lock.unlock();
            cond_var_.notify_one();
            // cond_var_.notify_all();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }

    void ExtractData() {
        auto id = std::this_thread::get_id();
        std::unique_lock<std::mutex> lock(mutex_);
        std::cout << "[Thread " << id << "] ExtractData(): Waiting" << std::endl;
        cond_var_.wait(lock, [this]() { return !data_.empty(); });
        auto val = data_.front();
        data_.pop();
        std::cout << "[Thread " << id << "] ExtractData(): data = " << val << std::endl;
    }

private:

    std::queue<int> data_;
    std::mutex mutex_;
    std::condition_variable cond_var_;
};


int main() {
    DataManager obj;
    std::thread t1(DataManager::AddData, &obj);
    std::thread t2(DataManager::ExtractData, &obj);
    std::thread t3(DataManager::ExtractData, &obj);
    
    t1.join();
    t2.join();
    t3.join();
    return 0;
}