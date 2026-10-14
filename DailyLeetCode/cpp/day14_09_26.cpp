#include <string> 

class Solution {
public:
    [[nodiscard]] std::string maxSumOfSquares(int num, int sum) const noexcept {
        if(num*9<sum){
            return "";
        }
        const int h9 = sum/9;
        std::string to_return;
        to_return.reserve(num);
        to_return.append(h9, '9');
        num-=h9;
        if(num==0){
            return to_return;
        }
        to_return.append(std::to_string(sum%9));
        num--;
        to_return.append(num, '0');
        
        return to_return;
    }
};