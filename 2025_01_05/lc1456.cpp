#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution{
public:
    int maxVowels(string s, int k){
        int res = 0;
        int n = s.size();
        unordered_set<char> ch = {'a', 'e', 'i', 'o', 'u'};
        // init
        for (int i = 0; i < k; ++i){
            if (ch.find(s[i]) != ch.end()){
                res = res + 1;
            }
        }
        int cur = res;
        // sliding window
        for (int i = k; i < n; ++i) {
            if(ch.find(s[i]) != ch.end()){
                cur = cur + 1;
            }
            if(ch.find(s[i-k]) != ch.end()){
                cur = cur - 1;
            }
            res = max(res, cur);
        }
        return res;
    }
};

int main(){
    Solution sol;

    // string s = "abciiidef";
    // int k = 3;

    // string s = "aeiou";
    // int k = 2;

    string s = "leetcode";
    int k = 3;

    cout << sol.maxVowels(s, k) << '\n';
    
    return 0;

}

int main() {
    vector<int> v = {2, 4, 6, 8, 10, 12, 14, 16, 18};
    vector<int>::iterator it = std::find(v.begin(), v.end(), 10); // find 10
    if (it != v.end())
        cout << "found " << *it << ", index: " << std::distance(v.begin(), it) << "\n";
    else
        cout << "not find\n";
    return 0;
}