#include <future>
#include <iostream>
#include <thread>
#include <vector>

std::mutex cout_mutex;

void teach(std::promise<void> &&promise) {
    std::cout << "class begins\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    promise.set_value();
    std::cout << "class ends\n";
}

void learn(std::shared_future<void> &shared_receiver) {
    shared_receiver.wait();
    std::lock_guard<std::mutex> guard(cout_mutex);
    std::cout << "thanks (" << std::this_thread::get_id() << ")\n";
}

int main() {
    std::promise<void> promise;
    // std::shared_future<void> shared_receiver = promise.get_future();
    std::shared_future<void> shared_receiver(promise.get_future());

    std::thread teacher(teach, std::move(promise));
    std::vector<std::thread> students;
    for (int i = 0; i < 5; ++i) {
        students.push_back(std::thread(learn, std::ref(shared_receiver)));
    }
    teacher.join();
    for (auto &s: students) s.join();

    return 0;
}