#include <vector>
#include <queue>
#include <array>
#include <cmath>

using namespace std;

class Solution {
    // i and j
    using point = pair<int, int>;
    // max change until now, point
    using edge = pair<int, point>;

public:
    int minimumEffortPath(const vector<vector<int>>& heights) const {
        constexpr int INF = 1e9;
        int n = heights.size();
        int m = heights[0].size();
        // rozwzamay miejsca gdzie dotad mamy jak najmniejsza zmiane
        priority_queue<edge, vector<edge>, greater<edge>> min_heap;
        min_heap.push({0, {0, 0}});
        vector<vector<int>> ab_height(n, vector<int>(m, INF));
        ab_height[0][0] = 0;

        // djikstra

        while (!min_heap.empty()) {
            const auto [change, point] = min_heap.top();
            min_heap.pop();
            const auto [row, col] = point;

            if (change > ab_height[row][col])
                continue;

            if (row == n - 1 && col == m - 1) {
                return ab_height[row][col];
            }
            constexpr array<int, 5> neighbours{1, 0, -1, 0, 1};

            for (int i = 0; i < 4; i++) {
                int const new_row = neighbours[i] + row;
                int const new_col = neighbours[i + 1] + col;

                if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m) { 
                    int new_abs_h = max(abs(heights[row][col]- heights[new_row][new_col]), ab_height[row][col]);
                    if (ab_height[new_row][new_col]>new_abs_h){
                        ab_height[new_row][new_col] = new_abs_h;
                        min_heap.push(
                            {ab_height[new_row][new_col], {new_row, new_col}});
                    }
                }
            }
        }
        return 0;
    }
};