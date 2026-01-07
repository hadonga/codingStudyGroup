#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int res = 0, n = s.size();
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < k; ++i) {
            if (vowels.find(s[i]) != vowels.end()) {
                res += 1;
            }
        }
        int cur = res;
        for (int i = k; i < n; ++i) {
            if (vowels.find(s[i]) != vowels.end()) {
                cur += 1;
            }
            if (vowels.find(s[i-k]) != vowels.end()) {
                cur -= 1;
            }
            res = max(res, cur);
        }
        return res;
    }
};

int main() {
    Solution sol;

    // string s = "abciiidef";
    // int k = 3; // res = 3

    // string s = "aeiou";
    // int k = 2; // res = 2

    string s = "leetcode";
    int k = 3; // res = 2

    cout << sol.maxVowels(s, k) << '\n';
    
    return 0;
}