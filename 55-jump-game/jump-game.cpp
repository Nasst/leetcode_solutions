#include <algorithm>
#include <vector>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        auto makeItIndex = static_cast<int_fast64_t>(nums.size() - 1);
        for(auto i = static_cast<int_fast64_t>(nums.size() - 1); i >= 0; i--) {
            if(i + nums[i] >= makeItIndex) {
                makeItIndex = i;
            }
        }
        return makeItIndex == 0;
    }
};