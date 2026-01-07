#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<string> solution(string &s) {
    vector<string> res;
    stack<string> res_back;
    // starting position of the left substr and the right substr
    int left = 0, right = s.size() - 1; 
    bool find = false;
    while (left <= right) {
        find = false;
        for (int k = 1; k <= (right-left+1)/2; ++k) {
            string tmp = s.substr(left, k); // starting position, size
            if (tmp == s.substr(right-k+1, k)) {
                res.push_back(tmp);
                res_back.push(tmp);
                left += k;
                right -= k;
                find = true;
                break;
            }
        }
        if (!find) {
            res.push_back(s.substr(left, right-left+1));
            break;
        }
    }
    while (!res_back.empty()) {
        res.push_back(res_back.top());
        res_back.pop();
    }
    return res;
}

int main() {
    // string s = "abcxyzxyabc";
    // string s = "abcxyxyabc";
    // string s = "abc";
    // string s = "aabbaa";
    string s = "abcxyzabxyabc";
    auto res = solution(s);
    for (auto str: res) {
        cout << str << ", ";
    }
    cout << '\n';
    return 0;
}



abcdeab
0123456   n=7

left = 0, right = 6
    (1) len = 1, 0 = a, 6 = b
    (2) len = 2, 01 = ab, 56 = ab, ok, res.push_back(ab)
        left = 2, right = 4

left = 2, right = 4
    (1) len = 1, 2 = c, 4 = e



01234, right - left = 4, len <= 2
    (1) 1 ~ 0, 4
    (2) 2 ~ 01, 34
    (3) 3 ~ 012, 234 x

012345, right - left = 5, len <= 3
    (1) 1,
    (2) 2: 01, 45
    (3) 3: 0123, 345
    (4) 4: 0123, 2345 x

len <= (right - left + 1) / 2




abcba
01234

s[0] = s[4]
s[1] = s[3]
