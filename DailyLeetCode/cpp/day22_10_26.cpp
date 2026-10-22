#include <vector>

class Solution {
public:
    [[nodiscard]] int minOperations(const std::vector<int>& nums) const noexcept {
        int len = nums.size();

        if(len == 1){
            return 0;
        }

        int dec_n =0, inc_n =0, dec_idx, inc_idx;
        for(int i=0; i<nums.size(); i++){
            int first = i;
            int second = i !=nums.size()-1 ? i+1 : 0;

            if(nums[first]<nums[second]){
                inc_n++;
                inc_idx=first;
            }
            if(nums[first]>nums[second]){
                dec_n++;
                dec_idx = first;
            }
        }
        if(dec_n == 1){

            //No use of rotation operation
            int no_rot = (dec_idx + 1)%len;

            // Two time use of rotation operation
            int with_rot = 1 + (len - 1 - dec_idx) + 1;

            return std::min(no_rot, with_rot);

        } else if (inc_n == 1){
            // Rot operation at the end.
            int rot_at_end = inc_idx + 1 + 1;

            // Rot operation at the start.
            int rot_at_start = 1 + (len - 1 - inc_idx);

            return std::min(rot_at_end, rot_at_start);

        }else{
            return -1;
        }
    }
};