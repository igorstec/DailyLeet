#include <string_view>
#include <algorithm>

class Solution {
public:
    [[nodiscard]] int maxDepth(std::string_view s) const noexcept {
        int max_v=0;
        int v=0;

        for(auto c : s){
            if(c=='('){
                v++;
                max_v = std::max(max_v, v);
            }else if (c==')'){
                v--;
            }
        }
        
        return max_v;
    }
};