#include <iostream>
#include <vector>

#include <algorithm>
#include <numeric>


using namespace std;

// float
// double
// int
// unsigned

int main() {
    vector<int> a = {1, 2, 3};
    a[2] = 100;
    int n = a.size();
    int a2 = a.back();
    // for (int i = 0; i < n; ++i) {
    //     cout << a[i] << '\n';  //不推荐用 std::endl
    // }

    // for (auto val: a) {
    //     cout << val << '\n';
    // }

    vector<vector<int>> b = {{1, 2, 3}, {4 ,5}};

    for (auto row:b) {
        for (auto val: row) {
            cout << val << ", ";
        }
        cout << '\n';
    }

    for (int i = 0; i < b.size(); ++i){
        for (int j =0; j < b[i].size(); ++j) cout << b[i][j] << '\n';
        cout << "haha\n";
    }

    int c = 100;
    {
        cout << "c = " << c << '\n';
        int d = 200;
    }
    // cout << "d = " << d << '\n'; // cannot compile

    vector<int> vec = {100, 20, -10, -200, 1000};
    sort(vec.begin()+2, vec.end());
    // {{1, 5, 2, 8}, {4, 5, 7, 2}}

    vector<vector<int>> arr = {
        {1,5,2,8,2},
        {4,5,7,2,4}
    };
    vector<int> idxs(arr[0].size(), 0);
    iota(idxs.begin(), idxs.end(), 0);
    sort(idxs.begin(), idxs.end(), [&](int i, int j) {
        // return arr[0][i] < arr[0][j];
        return (arr[0][i] < arr[0][j]) ||
               (arr[0][i] == arr[0][j] && arr[1][i] < arr[1][j]);
    }); // 0,1,2,3 -> 0,2,1,3
    for (auto idx: idxs) {
        cout << arr[0][idx] << ", ";
    }
    cout << '\n';
    for (auto idx: idxs) {
        cout << arr[1][idx] << ", ";
    }
    cout << '\n';

    for (auto &row: arr) {
        for (auto val: row) {
            cout << val << ", ";
        }
        cout << '\n';
    }




    return 0;
}
