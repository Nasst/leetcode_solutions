class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        auto elem = nums[0];
        auto count = 1;
        for(auto i = 1; i < nums.size(); i++) {
            if(count == 0) {
                elem = nums[i];
                count = 1;
            }
            else {
                if(nums[i] == elem) {
                    count++;
                }
                else {
                    count--;
                }
            }
        }
        return elem;
    }
};