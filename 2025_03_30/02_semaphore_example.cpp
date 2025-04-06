#include <array>
#include <thread>
#include <semaphore>
#include <mutex>
#include <chrono>
#include <iostream>
#include <random>

template<int N>
class Buffer {
public:
    Buffer(): sem_reader_(0), sem_writer_(N), gen_(rd_()) {
        buffer_.fill(' ');
        dist_data_ = std::uniform_int_distribution<int>(0, 25);
        dist_write_ = std::uniform_int_distribution<int>(1000, 1500);
        dist_read_ = std::uniform_int_distribution<int>(2000, 3000);
    }

    void Write(int iterations) {
        auto tid = std::this_thread::get_id();
        for (int i = 0; i < iterations * N; ++i) {
            char ch = 'a' + dist_data_(gen_);
            std::this_thread::sleep_for(std::chrono::milliseconds(dist_write_(gen_)));
            
            sem_writer_.acquire();
            buffer_[i % N] = ch;

            {
                std::lock_guard<std::mutex> lock(mutex_);
                std::cout << "[Thread " << tid << "] Writing " << ch << " to the buffer: ";
                Print();
            }

            sem_reader_.release();
        }
    }

    void Read(int iterations) {
        auto tid = std::this_thread::get_id();
        for (int i = 0; i < iterations * N; ++i) {
            sem_reader_.acquire();
            int idx = i % N;
            auto data = buffer_[idx];
            buffer_[idx] = ' ';
            {
                std::lock_guard<std::mutex> lock(mutex_);
                std::cout << "[Thread " << tid << "] Read " << data << " from the buffer : ";
                Print();
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(dist_read_(gen_)));

            sem_writer_.release();
        }
    }

    void Print() {
        std::cout << '|';
        for (auto data: buffer_) {
            std::cout << data << "|";
        }
        std::cout << std::endl;
    }

private:
    std::array<char, N> buffer_;
    std::counting_semaphore<N> sem_writer_;
    std::counting_semaphore<N> sem_reader_;
    std::mutex mutex_;

    std::random_device rd_;
    std::mt19937 gen_;
    std::uniform_int_distribution<int> dist_data_;
    std::uniform_int_distribution<int> dist_write_;
    std::uniform_int_distribution<int> dist_read_;
};

int main() {
    const int N = 5;
    Buffer<N> obj;

    int iterations = 3;
    std::thread t1(Buffer<N>::Write, &obj, iterations);
    std::thread t2(Buffer<N>::Read, &obj, iterations);
    t1.join();
    t2.join();

    return 0;
}