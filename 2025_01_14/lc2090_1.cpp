#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size(), len = 2 * k + 1;
        vector<int> res(n, -1);
        if (n < len) return res;

        long long s = 0;
        for (int i = 0; i <= 2*k; ++i) {
            s += nums[i];
        }
        res[k] = s / len;
        for (int i = k+1; i < n-k; ++i) {
            s += nums[i+k] - nums[i-k-1];
            res[i] = s / len;
        }
        return res;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {7,4,3,9,1,8,5,2,6};
    int k = 3;
    
    auto res = sol.getAverages(nums, k);

    for (int val: res) cout << val << ", ";
    cout << '\n';
    return 0;
}