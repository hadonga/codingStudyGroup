// 1. 调用条件变量的wait() 前，当前线程必须已经获得了这个互斥量
// 2. 进入wait()后，这个互斥量会被释放，并进入阻塞等待状态
// 3. 当另一个线程调用该条件变量的notify_one()或notify_any()，wait()会结束阻塞，同时试图再次获得这个互斥量
// 4. 唤醒丢失
// 5. 虚假唤醒：等待线程在条件未满足的情况下被唤醒（操作系统层面原因，或人为编码错误）

#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <iostream>

class DataManager {
public:

    void AddData(int data) {
        std::unique_lock<std::mutex> lock(mutex_);
        data_.push(data);
        std::cout << "[Thread " << std::this_thread::get_id() << "] AddData(): Done" << std::endl;
        lock.unlock();
        cond_var_.notify_one();
    }

    void ExtractDataWrong() {
        auto id = std::this_thread::get_id();
        std::unique_lock<std::mutex> lock(mutex_);
        std::cout << "[Thread " << id << "] ExtractData(): Waiting" << std::endl;
        cond_var_.wait(lock);
        auto val = data_.front();
        data_.pop();
        std::cout << "[Thread " << id << "] ExtractData(): data = " << val << std::endl;
    }

    void ExtractDataCorrect() {
        auto id = std::this_thread::get_id();
        std::unique_lock<std::mutex> lock(mutex_);
        std::cout << "[Thread " << id << "] ExtractData(): Waiting" << std::endl;
        // Method 1
        while (data_.empty()) {
            cond_var_.wait(lock);
        }
        // // Method 2
        // cond_var_.wait(lock, [this]() {
        //     return !data_.empty();
        // });

        if (data_.empty()) {
            std::cout << "[Thread " << id << "] ExtractData(): Spurious wakeup" << std::endl;
        }
        else {
            auto val = data_.front();
            data_.pop();
            std::cout << "[Thread " << id << "] ExtractData(): data = " << val << std::endl;
        }
    }

private:

    std::queue<int> data_;
    std::mutex mutex_;
    std::condition_variable cond_var_;
};

int main() {
    DataManager obj;
    std::thread t1(DataManager::AddData, &obj, 2);
    // std::thread t2(DataManager::ExtractDataWrong, &obj);
    std::thread t2(DataManager::ExtractDataCorrect, &obj);
    
    t1.join();
    t2.join();
    return 0;
}