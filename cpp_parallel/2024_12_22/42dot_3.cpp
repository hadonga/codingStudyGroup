#include <iostream>
#include <vector>
#include <string>

using namespace std;

// vector<int> solution(vector<int> &black_caps) {
//     int n = black_caps.size();
//     vector<int> answer(n, 0);

//     if (black_caps[0] == 1) answer[1] = 1;
//     else answer[1] = 2;
//     if (black_caps[n-1] == 1) answer[n-2] = 1;
//     else answer[n-2] = 2;
//     for (int i = 1; i < n-1; ++i) {
//         if (black_caps[i] == 2) {
//             answer[i-1] = 1;
//             answer[i+1] = 1;
//         }
//         else if (black_caps[i] == 0) {
//             answer[i-1] = 2;
//             answer[i+1] = 2;
//         }
//     }

//     int left = 1, right = n-2;
//     while (left <= right) {
//         if (black_caps[left] == 2) {
//             answer[left-1] = 1;
//             answer[left+1] = 1;
//         }
//         else if (black_caps[left] == 0) {
//             answer[left-1] = 2;
//             answer[left+1] = 2;
//         }
//         else {
//             if (answer[left-1] == 1) answer[left+1] = 2;
//             else if (answer[left-1] == 2) answer[left+1] = 1;
//         }

//         if (black_caps[right] == 2) {
//             answer[right-1] = 1;
//             answer[right+1] = 1;
//         }
//         else if (black_caps[right] == 0) {
//             answer[right-1] = 2;
//             answer[right+1] = 2;
//         }
//         else {
//             if (answer[right+1] == 1) answer[right-1] = 2;
//             else if (answer[right+1] == 2) answer[right-1] = 1;
//         }

//         // Check again.
//         if (black_caps[left] == 1) {
//             if (answer[left+1] == 1) answer[left-1] = 2;
//             else if (answer[left+1] == 2) answer[left-1] = 1;
//         }
//         if (black_caps[right] == 1) {
//             if (answer[right-1] == 1) answer[right+1] = 2;
//             else if (answer[right-1] == 2) answer[right+1] = 1;
//         }

//         left += 1;
//         right -= 1;
//     }

//     return answer;
// }


// vector<int> solution(vector<int> &black_caps) {
//     int n = black_caps.size();
//     vector<int> answer(n, 0);

//     if (black_caps[0] == 1) answer[1] = 1;
//     else answer[1] = 2;
//     if (black_caps[n-1] == 1) answer[n-2] = 1;
//     else answer[n-2] = 2;
//     for (int i = 1; i < n-1; ++i) {
//         if (black_caps[i] == 2) {
//             answer[i-1] = 1;
//             answer[i+1] = 1;
//         }
//         else if (black_caps[i] == 0) {
//             answer[i-1] = 2;
//             answer[i+1] = 2;
//         }
//     }

//     while (true) {
//         vector<int> tmp = answer;
//         bool same = true; // added
//         for (int i = 1; i < n-1; ++i) {
//             if (black_caps[i] == 1) {
//                 int left = tmp[i-1], right = tmp[i+1]; // added

//                 if (tmp[i-1] == 1) tmp[i+1] = 2;
//                 else if (tmp[i-1] == 2) tmp[i+1] = 1;

//                 if (tmp[i+1] == 1) tmp[i-1] = 2;
//                 else if (tmp[i+1] == 2) tmp[i-1] = 1;

//                 if (left != tmp[i-1] || right != tmp[i+1]) same = false; // added
//             }
//         }

//         if (same) break;
//         else answer = tmp;
//     }

//     return answer;
// }


// vector<int> solution(vector<int> &black_caps) {
//     int n = black_caps.size();
//     vector<int> answer(n, 0);

//     if (black_caps[0] == 1) answer[1] = 1;
//     else answer[1] = 2;
//     if (black_caps[n-1] == 1) answer[n-2] = 1;
//     else answer[n-2] = 2;
//     for (int i = 1; i < n-1; ++i) {
//         if (black_caps[i] == 2) {
//             answer[i-1] = 1;
//             answer[i+1] = 1;
//         }
//         else if (black_caps[i] == 0) {
//             answer[i-1] = 2;
//             answer[i+1] = 2;
//         }
//     }

//     vector<int> tmp = answer;
//     while (true) {
//         bool same = true; // added
//         for (int i = 1; i < n-1; ++i) {
//             if (black_caps[i] == 1) {
//                 int left = tmp[i-1], right = tmp[i+1]; // added

//                 if (tmp[i-1] == 1) tmp[i+1] = 2;
//                 else if (tmp[i-1] == 2) tmp[i+1] = 1;

//                 if (tmp[i+1] == 1) tmp[i-1] = 2;
//                 else if (tmp[i+1] == 2) tmp[i-1] = 1;

//                 if (left != tmp[i-1] || right != tmp[i+1]) {
//                     same = false; // added
//                     answer[i-1] = tmp[i-1]; // added
//                     answer[i+1] = tmp[i+1]; // added
//                 }
//             }
//         }

//         if (same) break;
//     }

//     return answer;
// }


// vector<int> solution(vector<int> &black_caps) {
//     int n = black_caps.size();
//     vector<int> answer(n, 0);

//     if (black_caps[0] == 1) answer[1] = 1;
//     else answer[1] = 2;
//     if (black_caps[n-1] == 1) answer[n-2] = 1;
//     else answer[n-2] = 2;
//     for (int i = 1; i < n-1; ++i) {
//         if (black_caps[i] == 2) {
//             answer[i-1] = 1;
//             answer[i+1] = 1;
//         }
//         else if (black_caps[i] == 0) {
//             answer[i-1] = 2;
//             answer[i+1] = 2;
//         }
//     }

//     while (true) {
//         bool same = true; // added
//         for (int i = 1; i < n-1; ++i) {
//             if (black_caps[i] == 1) {
//                 int left = answer[i-1], right = answer[i+1]; // added

//                 if (answer[i-1] == 1) answer[i+1] = 2;
//                 else if (answer[i-1] == 2) answer[i+1] = 1;

//                 if (answer[i+1] == 1) answer[i-1] = 2;
//                 else if (answer[i+1] == 2) answer[i-1] = 1;

//                 if (left != answer[i-1] || right != answer[i+1]) {
//                     same = false;
//                 }
//             }
//         }

//         if (same) break;
//     }

//     return answer;
// }


vector<int> solution(vector<int> &black_caps) {
    int n = black_caps.size();
    vector<int> answer(n, 0);

    if (black_caps[0] == 1) answer[1] = 1;
    else answer[1] = 2;
    if (black_caps[n-1] == 1) answer[n-2] = 1;
    else answer[n-2] = 2;
    for (int i = 1; i < n-1; ++i) {
        if (black_caps[i] == 2) {
            answer[i-1] = 1;
            answer[i+1] = 1;
        }
        else if (black_caps[i] == 0) {
            answer[i-1] = 2;
            answer[i+1] = 2;
        }
    }

    while (true) {
        bool update = false; // added
        for (int i = 1; i < n-1; ++i) {
            if (black_caps[i] == 1 &&
                ((answer[i-1] == 0 && answer[i+1] != 0) ||
                 (answer[i-1] != 0 && answer[i+1] == 0))) {

                if (answer[i-1] == 1) answer[i+1] = 2;
                else if (answer[i-1] == 2) answer[i+1] = 1;

                if (answer[i+1] == 1) answer[i-1] = 2;
                else if (answer[i+1] == 2) answer[i-1] = 1;

                // if (answer[i-1] == 0) answer[i-1] = 3 - answer[i+1];
                // else answer[i+1] = 3 - answer[i-1];

                update = true;
            }
        }

        if (!update) break;
    }

    return answer;
}

int main() {
    // vector<int> black_caps = {1,1,2,0}; // 1,1,2,1
    // vector<int> black_caps = {1,1,1}; // 0,1,0
    // vector<int> black_caps = {0,1,1,2,1}; // 2,2,1,1,1
    vector<int> black_caps = {1,1,1,1,1,2,1}; // 1,1,2,2,1,1,1
    auto res = solution(black_caps);
    for (auto val: res) cout << val << ", ";
    cout << '\n';

    return 0;
}