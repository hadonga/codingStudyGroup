#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int n = nums.size();
        int left = 0, right = n-1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int num = nums[mid];
            if (num == target) {
                res[0] = mid;
            }

            if (num >= target) {
                right = mid - 1;
            }
            // else if (num == target) {
            //     right = mid - 1;
            // }
            else {
                left = mid + 1;
            }
        }

        left = 0;
        right = n-1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int num = nums[mid];
            if (num == target) {
                res[1] = mid;
            }

            if (num > target) {
                right = mid - 1;
            }
            // else if (num == target) {
            //     left = mid + 1;
            // }
            else {
                left = mid + 1;
            }
        }

        return res;
    }
};