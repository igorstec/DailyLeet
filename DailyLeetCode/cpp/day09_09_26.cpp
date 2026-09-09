
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    [[nodiscard]] long long countCommas(long long n) const {
        long long wynik=0;
        long long k = n;
        long long mnoznik=1;
        while(mnoznik<static_cast<long long>(10e15) && k/mnoznik>999){
            k-=999ll*mnoznik;
            wynik+=k;
            mnoznik*=1000ll;
        }
        return wynik;
    }
};