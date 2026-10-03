#include <string_view>
#include <algorithm>

class Solution {
public:
    [[nodiscard]] int
    longestValidParentheses(std::string_view s) const noexcept {
        int i = 0;
        int current_size = 0;
        int max_l = 0;
        int counter = 0;
        int len = static_cast<int>(s.length());

        while (i < len) {
            if (s[i] == '(') {
                counter++;
            } else {
                counter--;
            }
            if (counter < 0) {
                current_size = 0;
                counter = 0;
                i++;
                continue;
            }
            current_size++;
            if (counter == 0) {
                max_l = std::max(max_l, current_size);
            }
            i++;
        }

        i = len - 1;
        current_size = 0;
        int max_e = 0;
        counter = 0;
        while (i >= 0) {
            if (s[i] == ')') {
                counter++;
            } else {
                counter--;
            }
            if (counter < 0) {
                current_size = 0;
                counter = 0;
                i--;
                continue;
            }
            current_size++;
            if (counter == 0) {
                max_e = std::max(max_e, current_size);
            }

            i--;
        }

        return std::max(max_l, max_e);
        // ((())))
    }
};