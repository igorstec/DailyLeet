#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        ranges::sort(coins);
        vector<int> filtered_coins;
        for (int coin : coins) {
            bool is_redundant = false;
            for (int fc : filtered_coins) {
                if (coin % fc == 0) {
                    is_redundant = true;
                    break;
                }
            }
            if (!is_redundant) {
                filtered_coins.push_back(coin);
            }
        }
        
        int n = filtered_coins.size();
        
        // Precompute the LCM for all subsets (bitmasks)
        // This makes the binary search much faster.
        int total_subsets = 1 << n;
        vector<long long> subset_lcm(total_subsets, 1);
        vector<int> set_bits_count(total_subsets, 0);
        
        for (int mask = 1; mask < total_subsets; ++mask) {
            long long current_lcm = 1;
            int bits = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    bits++;
                    // Calculate LCM: (a / gcd(a,b)) * b
                    long long g = std::gcd(current_lcm, (long long)filtered_coins[i]);
                    current_lcm = (current_lcm / g) * filtered_coins[i];
                    
                    // Safety break to prevent overflow during LCM calculation
                    // If LCM exceeds our max possible boundary, we cap it.
                    if (current_lcm > 50000000000LL) {
                        current_lcm = 50000000000LL + 1; // Just something larger than max possible M
                        break;
                    }
                }
            }
            subset_lcm[mask] = current_lcm;
            set_bits_count[mask] = bits;
        }

        // Binary Search
        long long left = 1;
        long long right = (long long)filtered_coins[0] * k; // Max possible answer
        long long ans = right;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long count = 0;

            // Apply Principle of Inclusion-Exclusion (PIE)
            for (int mask = 1; mask < total_subsets; ++mask) {
                if (set_bits_count[mask] % 2 == 1) {
                    count += mid / subset_lcm[mask]; // Add odd sized sets
                } else {
                    count -= mid / subset_lcm[mask]; // Subtract even sized sets
                }
            }

            if (count >= k) {
                ans = mid;        // Potential answer, try to find a smaller one
                right = mid - 1;
            } else {
                left = mid + 1;   // Count is too small, need a larger number
            }
        }

        return ans;
    }
};