#include <vector>
#include <array>
#include <algorithm>

class Solution {
public:
    // [[nodiscard]] informs the compiler that ignoring the return value of this function is a bug.
    // Passing input as a const reference prevents unintended modifications (e.g., sorting).
    // The trailing const means the function does not modify the object's state.
    [[nodiscard]] int largestInteger(const std::vector<int>& nums, const int k) const {
        const int n = static_cast<int>(nums.size());

        // Case 1: k == n
        // The entire array is the only subarray, so every element appears exactly once.
        if (k == n) {
            return *std::ranges::max_element(nums);
        }

        // Case 2: k == 1
        // We are looking for the largest element that appears in the ENTIRE array exactly once.
        // Problem constraints (nums[i] <= 50) allow us to use a super-fast frequency array with O(1) space.
        if (k == 1) {
            std::array<int, 51> freq{};
            for (const int num : nums) {
                freq[num]++;
            }
            
            // We iterate backwards, so the first unique element we find is guaranteed to be the largest.
            for (int i = 50; i >= 0; --i) {
                if (freq[i] == 1) {
                    return i;
                }
            }
            return -1;
        }

        // Case 3: 1 < k < n
        // Mathematically: any element strictly inside the array (indices 1..n-2) belongs to at least two 
        // subarrays of length k. The only valid candidates are the first and last elements, provided 
        // they do not duplicate anywhere else in the array.
        int max_val = -1;
        const int first_val = nums.front();
        const int last_val  = nums.back();

        if (std::ranges::count(nums, first_val) == 1) {
            max_val = std::max(max_val, first_val);
        }
        
        if (std::ranges::count(nums, last_val) == 1) {
            max_val = std::max(max_val, last_val);
        }

        return max_val;
    }
};