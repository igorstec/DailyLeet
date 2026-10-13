#include <vector>
#include <algorithm>
#include <cmath>


class Solution {
public:
    [[nodiscard]] long long maxAlternatingSum(std::vector<int>& nums) const noexcept {
        const int len = nums.size();
        const int k_th = len / 2;

        std::ranges::nth_element(nums, nums.begin() + k_th, std::less{}, [](const int x) {
            return std::abs(x);
        });

        long long result = 0LL;
        
        const int* data = nums.data();

        for (int i = 0; i < k_th; ++i) {
            result -= 1LL * data[i] * data[i];
        }

        for (int i = k_th; i < len; ++i) {
            result += 1LL * data[i] * data[i];
        }
        
        return result;
    }
};