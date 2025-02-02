#include<string>
#include<unordered_map>
#include<iostream>

using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {

        int start = 0, maxlen = 0;
        unordered_map<char,int> cnt;

        for (int end = 0; end < s.size(); ++end){
            while(cnt[s[end]]>1){
                cnt[s[start]] -= 1;
                start +=1;
            }
            cnt[s[end]] += 1;

            maxlen = max(maxlen, end -start +1);

            cout<< cnt[s[end]] << '\n';
        }
    return maxlen;
    }
};

int main(){
    Solution sol;

    // //case1
    // string s = "bcbbbcba";

    //case2
    string s ="aaaa";
    
    cout<< sol.maximumLengthSubstring(s) << '\n';
    return 0;
}
