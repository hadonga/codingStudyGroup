#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0, vowel = 0;
        unordered_set<char> chars ={'a','e','i','o','u'};
       
        for (int i = 0; i < s.length(); ++i){
            // 1. in window
            if (chars.find(s[i]) != chars.end()) {
                    vowel +=1;
                }
                
            if (i < k - 1) {
                continue;
                }
            
            // 2. update
            ans = max(ans, vowel);
            
            // 3. out window
            char out = s[i - k + 1];
            if (chars.find(s[i - k + 1]) != chars.end()) {
                vowel -=1;
                }
        }
    return ans;
    }
};

int main(){
    Solution sol;
    string s= "abciiidef";
    int k = 3;
    // string s = "leetcode";
    // int k = 3;

    cout << sol.maxVowels(s, k) << '\n';

    return 0;
}