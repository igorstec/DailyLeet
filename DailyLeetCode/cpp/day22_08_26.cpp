#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
    pair<int, int> digitSum(int n) {
        int sum = 0;
        int product = 1;
        int mod = 10;
        while (n != 0) {
            int num = (n % mod);
            sum += num;
            product *= num;
            n /= 10;
        }
        return {sum, product};
    }

public:
    bool checkDivisibility(int n) {
        auto [sum, product] = digitSum(n);
        return !(n % (sum + product));
    }
};