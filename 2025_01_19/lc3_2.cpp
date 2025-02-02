#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
public:
    int lengthOfLongestSubstring(string s){
        vector<int> cnt(26, 0);
        int res = 0, left = 0;

        for (int right = 0; right < s.size(); ++right ){
            while (cnt[s[right] - 'a']){
                cnt[s[left] - 'a'] -= 1;
                left += 1;
            }    
            cnt[s[right] - 'a'] += 1;
            for(auto i:cnt){
                cout << i << ", ";
            }
            cout << '\n';
            res = max(res, right - left + 1);
    }
    return res;
    }
};


int main(){
    Solution sol;

    //case1
    string s ="abcabcbb";

    cout << sol.lengthOfLongestSubstring(s) << '\n';
    return 0;
}