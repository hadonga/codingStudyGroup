#include<vector>
#include<string>
#include<iostream>


using namespace std;


class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
         int len = t.size();
        vector<int> costArr(len, 0 );
       
        for(int i = 0; i < len; ++i){
            costArr[i] = abs(s[i] - t[i]);
        }

        int left = 0, curCost = 0, maxlen = 0;
        for(int right = 0; right < len; ++right){
            curCost += costArr[right];
            while(curCost > maxCost){
                curCost -= costArr[left];
                left += 1;
            }
            maxlen = max(maxlen, right - left + 1);
            
        } 
        return maxlen;
    }
};


int main(){
    
    Solution sol;
    string s = "abcd" , t = "bcdf";
    int maxCost = 3;
    cout << sol.equalSubstring(s, t, maxCost) << '\n';
    
    return 0;
}