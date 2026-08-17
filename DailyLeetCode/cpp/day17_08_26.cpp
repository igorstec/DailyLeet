#include <iostream>
#include <ranges>
#include <numeric>
using namespace std;

class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        const int n = stoneValue.size();
        if (n <= 1) return 0;

        // Prefix sums for O(1) range sum queries
        vector<int> prefix(n + 1, 0);
        partial_sum(stoneValue.begin(), stoneValue.end(), prefix.begin() + 1);
        auto rangeSum = [&](int l, int r) { return prefix[r + 1] - prefix[l]; };

        // dp[l][r]      = max score obtainable from stoneValue[l..r]
        // bestLeft[l][r]  = max over k in [l,r] of rangeSum(l,k) + dp[l][k]  (best "keep left part" candidate)
        // bestRight[l][r] = max over k in [l,r] of rangeSum(k,r) + dp[k][r]  (best "keep right part" candidate)
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<int>> bestLeft(n, vector<int>(n, 0));
        vector<vector<int>> bestRight(n, vector<int>(n, 0));

        for (int l = n - 1; l >= 0; --l) {
            bestLeft[l][l] = bestRight[l][l] = rangeSum(l, l); // dp[l][l] == 0

            int mid = l; // amortized two-pointer, only moves forward as r grows
            for (int r = l + 1; r < n; ++r) {
                int total = rangeSum(l, r);

                // Advance mid to the first split point where the left half exceeds half of total
                while (mid < r && 2 * rangeSum(l, mid) <= total) ++mid;

                int best = 0;

                // Splits k < mid: left half <= right half -> keep left half
                if (mid - 1 >= l) best = max(best, bestLeft[l][mid - 1]);

                // Splits k >= mid: right half <= left half -> keep right half
                int rightRangeStart = mid;
                // If split at mid-1 is an exact tie, it's also a valid "keep right half" option
                if (mid - 1 >= l && 2 * rangeSum(l, mid - 1) == total) rightRangeStart = mid - 1;
                if (rightRangeStart < r) best = max(best, bestRight[rightRangeStart + 1][r]);

                dp[l][r] = best;

                // Extend running-max tables in O(1)
                bestLeft[l][r] = max(bestLeft[l][r - 1], total + dp[l][r]);
                bestRight[l][r] = max(bestRight[l + 1][r], total + dp[l][r]);
            }
        }

        return dp[0][n - 1];
    }
};