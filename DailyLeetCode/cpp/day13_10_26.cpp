#include <vector>
#include <algorithm>
#include <cmath>


class Solution {
public:
    [[nodiscard]] long long maxAlternatingSum(std::vector<int>& nums) const noexcept {
        const int len = nums.size();
        const int k_th = len/2; // [2,1,3] -> 1
        std::ranges::for_each(nums, [](int& x){x = std::abs(x);});
        std::ranges::nth_element(nums, nums.begin()+k_th);

        long long result=0ll;
        if(len % 2 ==1){
            result=nums[k_th]*nums[k_th];
        }
        for(int i=0; i<k_th; i++){
            result+=((nums[i]+nums[len-1-i])*(nums[len-1-i]-nums[i]));
        }
        return result;
    }
};