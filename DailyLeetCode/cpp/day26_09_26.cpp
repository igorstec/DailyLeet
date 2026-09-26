#include <unordered_map>
#include <vector>
#include <string>

class Solution {
public:
    [[nodiscard]] std::string
    evaluate(const std::string& s,
             const std::vector<std::vector<std::string>>& knowledge) const {
        
        // Mapa referencji widoków - zero alokacji na klucze i wartości
        std::unordered_map<std::string_view, std::string_view> dictionary;
        dictionary.reserve(knowledge.size());
        for (const auto& entry : knowledge) {
            dictionary.emplace(entry[0], entry[1]);
        }

        std::string result;
        result.reserve(s.length());

        const std::string_view sv = s;
        const std::size_t n = sv.length();
        std::size_t i = 0;

        while (i < n) {
            if (sv[i] == '(') {
                const std::size_t start = ++i;
                while (i < n && sv[i] != ')') {
                    ++i;
                }
                
                const std::string_view key = sv.substr(start, i - start);
                const auto it = dictionary.find(key);
                if (it != dictionary.end()) {
                    result += it->second;
                } else {
                    result += '?';
                }
                ++i; // pomiń zamykający nawias ')'
            } else {
                result += sv[i];
                ++i;
            }
        }

        return result;
    }
};