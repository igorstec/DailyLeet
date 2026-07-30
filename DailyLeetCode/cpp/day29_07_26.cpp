#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    const int INF = 1e6 + 1; // K <= 10^6, to nasz jedyny bezpieczny limit

    // Niesamowicie szybkie nCr. Bez GCD, z natychmiastowym przerywaniem
    long long nCr(int n, int k, int ktorejszukam) {
        if (k < 0 || k > n) return 0;
        k = std::min(k, n - k);
        if (k == 0) return 1;
        
        long long res = 1;
        for (int i = 1; i <= k; ++i) {
            // (res * (n - i + 1)) nigdy nie przebije ~10^10, co bezpiecznie mieści się w long long.
            // Zawsze dzieli się to bez reszty przez i (wynika z właściwości symbolu Newtona)
            res = res * (n - i + 1) / i;
            
            // Jeśli przekraczamy K, ucinamy – ta pętla prawie nigdy nie zrobi więcej niż 6 obiegów!
            if (res > ktorejszukam) return INF; 
        }
        return res;
    }

    long long ile_zostalo_permutacji(int len, const vector<int>& znaki, int ktorejszukam) {
        long long wynik = 1;
        int pozostala_dlugosc = len;
        
        for (int znak_count : znaki) {
            if (znak_count == 0) continue;
            
            long long combinations = nCr(pozostala_dlugosc, znak_count, ktorejszukam);
            
            if (wynik > INF / combinations) {
                return INF;
            }
            
            wynik *= combinations;
            pozostala_dlugosc -= znak_count;
        }
        
        return wynik;
    }

public:
    string smallestPalindrome(string s, int k) {
        // Zabezpieczenie przed k > 1 dla jednoznakowego stringa
        if (s.size() == 1) {
            return (k == 1) ? s : "";
        }

        int len = s.size() / 2;
        vector<int> znaki(26, 0);
        
        // Genialny skrót: pobranie dostępnej bazy liter od razu z połowy wejściowego stringa
        string mys = s.substr(0, len);
        for (char znak : mys) {
            znaki[znak - 'a']++;
        }

        // Czy w ogóle mamy wystarczająco permutacji?
        if (ile_zostalo_permutacji(len, znaki, k) < k) {
            return "";
        }

        long long ktorejszukam = k;
        string permutacja = "";
        permutacja.reserve(len);

        while (len > 0) {
            for (int id = 0; id < 26; ++id) {
                if (znaki[id] == 0) continue; 

                znaki[id]--;
                long long ile = ile_zostalo_permutacji(len - 1, znaki, ktorejszukam);

                if (ile >= ktorejszukam) {
                    permutacja.push_back((char)('a' + id));
                    len--;
                    break; 
                } else {
                    ktorejszukam -= ile;
                    znaki[id]++;
                }
            }
        }

        string reversed_permutacja = permutacja;
        reverse(reversed_permutacja.begin(), reversed_permutacja.end());

        if (s.size() % 2 == 0) {
            return permutacja + reversed_permutacja;
        } else {
            return permutacja + s[s.size() / 2] + reversed_permutacja;
        }
    }
};