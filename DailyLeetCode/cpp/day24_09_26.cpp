#include <span>
#include <ranges>
#include <optional>
#include <cstdlib>
#include <utility>
#include <cstddef>

class Solution {
[[nodiscard]] static constexpr int digit_sum(int num) noexcept {
    num = std::abs(num);
    int result = 0;
    while (num != 0) {
        result += num % 10;
        num /= 10;
    }
    return result;
}
public:
[[nodiscard]] static constexpr std::optional<std::size_t> find_smallest_matching_index(std::span<const int> nums) noexcept {
    // C++23 std::views::enumerate
    for (auto&& [idx, value] : std::views::enumerate(nums)) {
        if (digit_sum(value) == static_cast<int>(idx)) {
            return idx;
        }
    }
    return std::nullopt;
}
};