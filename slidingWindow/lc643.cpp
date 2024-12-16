class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int ans = -10e6, sum = 0;
        for (int i = 0; i < nums.size(); ++i){
            if (i < k){
                sum += nums[i];
            }
            else{
                sum += nums[i]-nums[i-k];
            }
            if (i >= k - 1) 
            ans = max(sum, ans);
        }
        return double(ans)/ double(k);
    }
};