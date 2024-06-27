#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        auto accumulator = 1;
        auto results = std::vector<int>(nums.size(), 1);
        for(auto i = 0; i < nums.size() - 1; i++) {
            accumulator *= nums[i];
            results[i + 1] *= accumulator;
        }
        accumulator = 1;
        for(auto i = nums.size() - 1; i > 0; i--) {
            accumulator *= nums[i];
            results[i - 1] *= accumulator;
        }
        return results;
    }
};