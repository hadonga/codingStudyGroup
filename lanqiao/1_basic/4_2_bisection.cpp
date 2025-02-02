//二分答案

// 模板

// bool check(int mid) {
//     bool res = true;
//     ...
//     return res;
// }

// int main() {
//     int left = 0, right = 1e9;
//     while (left + 1 != right) {
//         int mid = (right + lef) >> 1;
//         if( check(mid)) l= mid;
//         else r =mid;
//     }
//     return l; // 具体输出需要根据题意
// }

#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 9;
int a[N];
int L, n, m;

int check (int mid) {
    int res = 0, lst = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] - a[lst] < mid
    }
}

int main (){
    cin >> L >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int left = 0, right = 1e9 +5 ;
    while ( left + 1 != right) {
        int mid = (left + right) >> 1;
        if (check(mid) <= m) left = mid;
        else right = mid;
    }
    cout << left << "\n";
    return 0;
}

