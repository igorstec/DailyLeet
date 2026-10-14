#include <string> 

class Solution {
public:
    [[nodiscard]] std::string maxSumOfSquares(int num, int sum) const noexcept {
        if(num*9<sum){
            return "";
        }
        const int h9 = sum/9;
        const int m9 = sum%9;

        std::string to_return;
        to_return.reserve(num);

        to_return.append(h9, '9');

        if(m9>0){
            to_return.push_back(static_cast<char>('0' + m9));
        }
        
        to_return.append(num-to_return.size(), '0');
        
        return to_return;
    }
};