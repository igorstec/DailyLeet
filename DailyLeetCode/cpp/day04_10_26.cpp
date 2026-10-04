#include <string_view>
#include <vector>

class Solution {
public:
    [[nodiscard]] bool checkValidString(std::string_view s) const noexcept {
        // (*)
        std::vector<int> stac;
        std::vector<int> stac_star;
        for (int i = 0; i < static_cast<int>(s.length()); i++) {
            if (s[i] == '*') {
                stac_star.push_back(i);
            } else if (s[i] == '(') {
                stac.push_back(i);
            } else if (!stac.empty()) {
                stac.pop_back();
            } else if (!stac_star.empty()) {
                stac_star.pop_back();
            } else {
                return false;
            }
        }
        while (!stac.empty() && !stac_star.empty() &&
               stac.back() < stac_star.back()) {
            stac.pop_back();
            stac_star.pop_back();
        }

        if (stac.empty()) {
            return true;
        } else {
            return false;
        }
    }
};