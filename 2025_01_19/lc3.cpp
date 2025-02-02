//3. 无重复字符的最长子串

#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;

class Solution{
public:
    int lengthOfLongestSubstring(string s){
        int len = s.size();
        // // spc
        // if (len < 2){
        //     return len;
        // }

        int maxlen = 0;
        unordered_set<char> hash;
        int start = 0;
        for (int end = 0; end < len; ++ end){
            while(hash.count(s[end])){
                hash.erase(s[start]);
                start += 1;
            } 
            hash.insert(s[end]);

            maxlen = max(maxlen, end - start +1);
        }
    return maxlen;
    }
};

int main(){
    Solution sol;

    //case1
    string s ="abcabcbb";

    cout << sol.lengthOfLongestSubstring(s) << '\n';
    return 0;
}