#include <future>
#include <iostream>
#include <sstream>

// std::mutex cout_mutex;

void compute_pi(const long n_steps, std::promise<double> &&promise) {
    double step = 1.0 / n_steps;
    double s = 0;
    for (long i = 0; i < n_steps; ++i) {
        double x = (i + 0.5) * step;
        s += 4.0 / (x * x + 1);
    }
    promise.set_value(s * step);
}

void print1(std::shared_future<double> receiver) {
    double pi = receiver.get();
    
    // method 1
    // std::lock_guard<std::mutex> guard(cout_mutex);
    // std::cout << "estimate of pi: " << pi << '\n';

    // method 2
    printf("print1: estimate of pi: %f\n", pi);
}

void print2(std::shared_future<double> &receiver) {
    double pi = receiver.get();
    
    // method 1
    // std::lock_guard<std::mutex> guard(cout_mutex);
    // std::cout << "estimate of pi: " << pi << '\n';

    // method 2
    printf("print2: estimate of pi: %f\n", pi);
}


int main() {
    const long n_step = 1000;

    std::promise<double> promise;

    // method 1
    std::shared_future<double> shared_receiver(promise.get_future());

    // method 2
    // auto shared_receiver = promise.get_future().share();

    std::thread th1(compute_pi, n_step, std::move(promise));
    std::thread th2(print1, shared_receiver); // copy shared_receiver
    std::thread th3(print2, std::ref(shared_receiver)); // not copy shared_future

    th1.join();
    th2.join();
    th3.join();

    return 0;
}