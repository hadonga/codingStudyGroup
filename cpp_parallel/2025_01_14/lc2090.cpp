// 2090. K Radius Subarray Averages
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        int len = 2 * k + 1;
        long long sum = 0; 
        vector<int> ans(n, -1);

        if (n < len) return ans;
        // 1. init
        // k ~ n-k-1
        for (int i = 0; i < 2 * k + 1; ++i){
            sum += nums[i];
        }
        ans[k] = sum / len;

        for (int i = k + 1; i <= n - k - 1 ; ++i){
            sum += nums[i + k] - nums[i - k - 1];
            ans[i] = sum / len;
            }
        return ans;  
    }
};

int main(){
    Solution sol;

    vector<int> nums = {7,4,3,9,1,8,5,2,6};
    int k = 3;

    vector<int> ans = sol.getAverages(nums, k);
    for(auto i:ans) cout<< i << ", " ;
    cout << '\n';   
    return 0;
}