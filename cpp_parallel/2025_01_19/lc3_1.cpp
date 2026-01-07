#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
public:
    int lengthOfLongestSubstring(string s){
        vector<int> cnt(26, 0);
        int res = 0, left = 0;
        for (int right = 0; right < s.size(); ++right) {
            char ch = s[right];
            while (cnt[ch - 'a'] > 0) {
                cnt[s[left] - 'a'] -= 1;
                left += 1;
            }
            cnt[ch - 'a'] += 1;
            res = max(res, right - left + 1);
        }
        return res;
    }
};

int main() {
    Solution sol;

    //case1
    // string s ="abcabcbb"; // 3

    // case 2
    // string s = "bbbbb"; // 1

    // case 3
    string s = "pwwkew"; // 3

    cout << sol.lengthOfLongestSubstring(s) << '\n';
    return 0;
}