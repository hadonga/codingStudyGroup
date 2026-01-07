#include <future>
#include <iostream>

void compute_pi(const long n_steps, std::promise<double> &&promise) {
    double step = 1.0 / n_steps;
    double s = 0;
    for (long i = 0; i < n_steps; ++i) {
        double x = (i + 0.5) * step;
        s += 4.0 / (x * x + 1);
    }
    promise.set_value(s * step);
}

void print(std::future<double> &&receiver) {
    double pi = receiver.get();
    std::cout << "estimate of pi: " << pi << '\n';
}

int main() {
    const long n_steps = 1000;
    std::thread thr1, thr2;
    {
        std::promise<double> promise;
        auto receiver = promise.get_future();
        thr1 = std::thread(compute_pi, n_steps, std::move(promise));
        thr2 = std::thread(print, std::move(receiver));
    }
    thr1.join();
    thr2.join();

    return 0;
}