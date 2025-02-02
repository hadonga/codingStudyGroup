#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold){
        int target = k * threshold;
        int ans = 0, cur = 0;
        // 1. init
        for (int i = 0; i < k; ++i){
            cur += arr[i];
        }
        if (cur >= target) ans +=1;
        // 2. in and out
        for (int i = k; i < arr.size(); ++i){
            cur += arr[i] - arr[i-k];
            if (cur >= target) ans +=1;
        }
        return ans;
    }
};

int main(){

    Solution sol;
    // //case1
    // vector<int> arr = {2,2,2,2,5,5,5,8};
    // int k = 3, threshold = 4;
    // case2
    vector<int> arr = {11,13,17,23,29,31,7,5,2,3};
    int k = 3, threshold = 5;

    cout << sol.numOfSubarrays(arr, k, threshold) << '\n';
    return 0;
}