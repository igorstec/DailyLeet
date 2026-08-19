#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxNumberOfFamilies(const int n, const vector<vector<int>>& reservedSeats) const {
        static constexpr int bitOf[11] = {0, 0, 1, 1, 2, 2, 4, 4, 8, 8, 0};
        //                      indeks:   0  1  2  3  4  5  6  7  8  9 10

        unordered_map<int, int> blocked; // rząd -> maska zajętych półbloków
        for (const auto& s : reservedSeats) {
            int row = s[0], seat = s[1];
            blocked[row] |= bitOf[seat];// miejsca 1/10 rejestrują rząd z bit = 0
        }

        int ans = 2 * n;
        for (const auto& [row, mask] : blocked) {
            bool left = !(mask & 0b0011);
            bool mid = !(mask & 0b0110);
            bool right = !(mask & 0b1100);
            int nofits = (left && right) ? 0 : (left || mid || right) ? 1 : 2;
            ans -= nofits;
        }
        return ans;
    }
};