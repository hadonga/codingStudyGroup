//整数二分

#include <iostream>
#include <vector>

using namespace std;



// 最朴素的方法是用mid作为答案。
// int main(){

//     vector<int> a(200);
//     for (int i = 0; i < 200; i++){
//         a[i] = 4 * i + 6;
//     }
//     int res = -1;
//     int n; cin >> n;

//     int left = 0, right = a.size() - 1;
//     while( left <= right) {
//         int mid = left + (right - left) /2;
//         if (a[mid] == n) {
//             res = mid;
//             break;
//         }
//         else if (a[mid] > n) right = mid;
//         else left = mid; 
//     }
//     cout << res << "\n";
//     return 0;
// }

// 用right 作为答案：

int main(){
    vector<int> data(200);
    for (int i = 0; i < 200; ++i) data[i] = 4 * i + 6;
    int res = -1;
    int n; cin >> n;
    int left = -1, right = data.size() -1;
    while (left + 1 != right) {
        int mid = left + (right - left) /2;
        if(data[mid] >= n) right = mid;
        else left =mid;
    }
    res = right;
    cout << res << "\n";
    return 0;

}