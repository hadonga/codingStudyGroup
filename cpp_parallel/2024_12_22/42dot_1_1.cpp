#include <iostream>
#include <vector>

using namespace std;

int solution(int price, vector<vector<int>> &info) {
    long long p = price;
    long long total = p * info[0][0] + info[0][1];
    
    // long long total = (long long)price * info[0][0] + info[0][1];

    int res = 1, size = info[0][0];
    for (int i = 1; i < info.size(); ++i) {
        long long tmp = p * info[i][0] + info[i][1];
        if (tmp < total || (tmp == total && info[i][0] < size)) {
            total = tmp;
            res = i + 1;
            size = info[i][0];
        }
    }
    return res;
}

int main() {
    // int price = 20000;
    // vector<vector<int>> info = {
    //     {20, 150000},
    //     {80, 30000},
    //     {63, 70000},
    //     {21, 20000}
    // };

    // int price = 20000;
    // vector<vector<int>> info {
    //     {20, 150000},
    //     {40, 30000},
    //     {25, 70000}
    // };

    int price = 30000;
    vector<vector<int>> info {
        {30, 100000},
        {20, 400000}
    };

    cout << solution(price, info) << '\n';
    
    return 0;
}