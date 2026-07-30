using namespace std;
#include <iostream>

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        int idMax1 = 0, idMax2 = 1;
        if (nums[0] > nums[1]) {
            std::swap(idMax1, idMax2);
        }
        int i = 2;
        while (i < len) {
            if (nums[i] > nums[idMax1]) {
                if (nums[i] > nums[idMax2]) {
                    idMax1 = idMax2;
                    idMax2 = i;
                } else {
                    idMax1 = i;
                }
            }
            i++;
        }

        return (nums[idMax1] - 1) * (nums[idMax2] - 1);
    }
};