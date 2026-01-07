#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// 需要优化， 不使用map
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int start = 0, maxlen = 0;
        unordered_map<int,int> hm;

        for (int end = 0; end < nums.size(); ++ end){
            hm[nums[end]] += 1;
            
            while(hm[0]> 1){
                hm[nums[start]] -= 1;
                start += 1;
                
            }
            maxlen = max(maxlen, end - start +1);
            cout<< "end :" << end << ';';
            cout<< "start :"<<start << '\n';
        }

    return maxlen - 1;
    }
};


int main(){
    Solution sol;
    // vector<int> nums = {1,1,0,1};
    // vector<int> nums = {0,1,1,1,0,1,1,0,1};
    vector<int> nums = {1,1,1,1,1};

    cout << sol.longestSubarray(nums) << '\n';
    return 0;
}