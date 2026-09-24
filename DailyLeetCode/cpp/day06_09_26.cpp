#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>

class Solution {
public:
    [[nodiscard]] int numDistinct(std::string s, std::string t) const {
        int m = s.length(), n = t.length();
        if (m < n) return 0;
        
        std::vector<unsigned long long> dp(n + 1, 0);
        dp[0] = 1;

        for (char c : s) {
            for (int j = n; j >= 1; --j) {
                if (c == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return static_cast<int>(dp[n]);
    }
};