#include <iostream>
#include <ranges>

using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, const int k) {
        if(k==nums.size()){
            //return max val
            return *ranges::max_element(nums);
        }else if (k==1){
            // return max val apearing once if exists
            // nums.size()>1
            ranges::sort(nums);
            int i = nums.size()-1;
            while(i>0 && nums[i]==nums[i-1]){
                i--;
                while(i>0 && nums[i]==nums[i+1]){
                    i--;
                }
            }
            if(i==0 && nums[i]==nums[i+1]){
                return -1;
            }else{
                return nums[i];
            }
        }else{
            // return first or last element if its the only one
            // we know nums.size() > 1 at this point
            int l = nums[0];
            int r = nums[nums.size()-1];
            int l_count = ranges::count(nums, l);
            int r_count = ranges::count(nums, r);
            if(l_count == 1 || r_count == 1){
                if(l_count != 1){
                    return r;
                }else if (r_count !=1){
                    return l;
                }else{
                    return max(l, r);
                }
            }else{
                return -1;
            }
        }
    }
};