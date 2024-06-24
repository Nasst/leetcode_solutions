#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        if(target <= nums.front()) {
            return 0;
        }
        if(target > nums.back()) {
            return nums.size();
        }
        if(target == nums.back()) {
            return nums.size() -  1;
        }
        auto frontIndex = 0;
        auto backIndex = static_cast<int>(nums.size()) - 1;
        while(frontIndex + 1 < backIndex) {
            auto midPoint = (frontIndex + backIndex) / 2;
            if(nums[midPoint] == target) {
                return midPoint;
            }
            else if(nums[midPoint] > target) {
                backIndex = midPoint;
            }
            else {
                frontIndex = midPoint;
            }
        }
        return frontIndex + 1;
    }
};