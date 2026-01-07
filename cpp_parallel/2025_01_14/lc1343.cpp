class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans = 0, sum =0;
        for (int i = 0; i < arr.size(); ++i){
            if (i < k){
                sum += arr[i];
            }
            else{
                sum = sum + arr[i] - arr[i - k];
            }
            if (i >= k - 1){
                if (double(sum)/double(k) >= threshold) ans += 1;
                }
        }
        return ans;
    }
};