#include <thread>
#include <iostream>
#include <array>

void print(int idx) {
    // std::cout << "print " << idx << '\n';
    printf("print %i\n", idx);
}

void update(int idx, int &val) {
    val = idx;
}

int main() {
    const int n = 3;
    std::array<std::thread, n> threads;
    for (int i = 0; i < n; ++i) {
        threads[i] = std::thread(print, i);

        // will throw errors
        // std::thread thr(print, i);
        // threads[i] = thr;
    }
    for (auto &t: threads) {
        t.join();
    }


    
    std::array<int, n> values;
    std::array<std::thread, n> new_threads;
    for (int i = 0; i < n; ++i) {
        new_threads[i] = std::thread(update, i, std::ref(values[i]));
    }
    for (int i = 0; i < n; ++i) {
        new_threads[i].join();
        std::cout << "values[" << i << "] = " << values[i] << '\n';
    }

    return 0;
}