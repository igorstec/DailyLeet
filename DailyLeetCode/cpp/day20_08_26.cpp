#include <vector>
using namespace std;

class Solution {
public:
    [[nodiscard]] vector<int> resultArray(const vector<int>& nums) const {
        if(nums.size() <= 2) {
            return nums;
        }
        
        vector<int> arr1{nums[0]};
        vector<int> arr2{nums[1]};
        
        for(int i = 2; i < nums.size(); ++i) {
            if(arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }
        
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};