#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>

class Solution {
public:
    [[nodiscard]] int firstStableIndex(const std::vector<int>& nums, int k) const {

        int len = static_cast<int>(nums.size());
        int min_r = INT_MAX;
        int max_l = INT_MIN;

        std::vector<int> min_arr_r(len);

        // Set the "minimum on the right" array
        for (int i = len - 1; i >= 0; i--) {
            min_r = std::min(min_r, nums[i]);
            min_arr_r[i] = min_r;
        }

        // Find a stab;le idx
        for (int i = 0; i < len; i++) {
            max_l = std::max(max_l, nums[i]);
            if (max_l - min_arr_r[i] <= k) {
                return i;
            }
        }

        // If does not exist such idx return -1
        return -1;
    }
};