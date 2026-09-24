
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {

    [[nodiscard]] int digit_sum(int num) {
        int result = 0;
        while (num != 0) {
            result += num % 10;
            num /= 10;
        }
        return result;
    }

public:
    int smallestIndex(vector<int>& nums) {
        int idx = 0;
        for (auto num : nums) {
            if (digit_sum(num) == idx) {
                return idx;
            }
            idx++;
        }
        return -1;
    }
};