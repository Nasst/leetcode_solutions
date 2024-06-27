#include <algorithm>
#include <cstdint>
#include <vector>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        auto numSize = static_cast<int_fast64_t>(nums.size());
        auto jumpsToEnd = std::vector<int_fast64_t>(numSize, INT_FAST64_MAX);
        jumpsToEnd[numSize - 1] = 0;
        for(auto index = numSize - 2; index >= 0; index--) {
            auto jumps = nums[index];
            if(index + jumps >= numSize - 1) {
                jumpsToEnd[index] = 1;
            }
            else {
                for(auto subIndex = index + jumps; subIndex > index; subIndex--) {
                    if(jumpsToEnd[subIndex] != INT_FAST64_MAX)
                        jumpsToEnd[index] = std::min(jumpsToEnd[index], jumpsToEnd[subIndex] + 1);
                }
            }
        }
        return jumpsToEnd[0];
    }
};