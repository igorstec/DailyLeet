#include <iostream>
class Solution {
public:
    int minimumPushes(const std::string &word) {
        int len = static_cast<int>(word.size());
        int howmany8 = len/8;
        return (howmany8 * 4 + len%8) * (howmany8+1);
    }
};