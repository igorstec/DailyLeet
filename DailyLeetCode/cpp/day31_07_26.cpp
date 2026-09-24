#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

class Solution {
public:
    int minimumPushes(const std::string &word) {
        std::vector<int> letters(26, 0);
        
        for(char c : word){
            letters[(int)(c - 'a')]++;
        }
        std::ranges::sort(letters, [](int a, int b) { return a > b; });

        int multiplier=1;
        int result=0;
        int which=0;
        for(auto values : letters){
            if(values == 0){
                break;
            }
            result += (multiplier * values);

            which++;
            if(which%8 == 0){
                multiplier++;
            }
        }
        return result;

    }
};