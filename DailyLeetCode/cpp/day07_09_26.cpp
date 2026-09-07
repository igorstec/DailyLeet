#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int distinctSubseqII(string s) {
        int mod = 1e9 + 7;
        // Stores the number of distinct subsequences ending with each letter
        vector<int> endsWith(26, 0);
        
        for (char c : s) {
            long long currentSum = 0;
            
            // 1. Count all distinct subsequences formed so far
            for (int count : endsWith) {
                currentSum = (currentSum + count) % mod;
            }
            
            // 2. Any previous subsequence can be appended with 'c', 
            // plus we can have a sequence of just 'c' itself (+1).
            // This overwrites any previous value for endsWith[c - 'a']
            // which automatically handles the deduplication!
            endsWith[c - 'a'] = (currentSum + 1) % mod;
        }
        
        // 3. The total is the sum of subsequences ending in ANY character
        long long total = 0;
        for (int count : endsWith) {
            total = (total + count) % mod;
        }
        
        return total;
    }
};