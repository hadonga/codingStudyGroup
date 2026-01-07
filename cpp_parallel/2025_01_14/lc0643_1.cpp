#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    double findMaxAverage(vector<int> &nums, int k){
        int ans = -10e6;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i < k){
                sum += nums[i];
            }
            else{
                sum += nums[i] - nums[i-k]; 
            }
            if (i >= k - 1) ans = max(ans, sum);
        }
        return double(ans)/ k;

    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,12,-5,-6,50,3};
    int k = 4;

    cout<< sol.findMaxAverage(nums, k) << '\n';

    return 0;
}