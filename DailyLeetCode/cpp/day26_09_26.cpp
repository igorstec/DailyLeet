#include <unordered_map>
#include <vector>
#include <string>

class Solution {
public:
    [[nodiscard]] std::string
    evaluate(const std::string& s,
             const std::vector<std::vector<std::string>>& knowledge) const {
        std::unordered_map<std::string, std::string> dictionary;
        dictionary.reserve(knowledge.size());
        for (const auto& entry : knowledge) {
            dictionary.emplace(entry[0], entry[1]);
        }

        std::string result;
        result.reserve(s.length());

        const std::size_t n = s.length();
        for (std::size_t i = 0; i < n; ++i) {
            if (s[i] == '(') {
                const std::size_t start = ++i;
                while (i < n && s[i] != ')') {
                    ++i;
                }
                
                const std::string key = s.substr(start, i - start);
                const auto it = dictionary.find(key);
                if (it != dictionary.end()) {
                    result += it->second;
                } else {
                    result += '?';
                }
            } else {
                result += s[i];
            }
        }

        return result;
    }
};