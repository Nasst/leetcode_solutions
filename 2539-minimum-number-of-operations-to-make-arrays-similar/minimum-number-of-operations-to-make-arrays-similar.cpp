#include <algorithm>
#include <cmath>
#include <vector>

class Solution {
public:
    long long makeSimilar(std::vector<int>& nums, std::vector<int>& target) {
        std::sort(nums.begin(), nums.end());
        std::sort(target.begin(), target.end());
        auto numOdds = std::vector<int>();
        auto targetOdds = std::vector<int>();
        auto numEvens = std::vector<int>();
        auto targetEvens = std::vector<int>();
        for(auto i = 0; i < nums.size(); i++) {
            if(nums[i] % 2 == 0) {
                numEvens.push_back(nums[i]);
            } else {
                numOdds.push_back(nums[i]);
            }
            if(target[i] % 2 == 0) {
                targetEvens.push_back(target[i]);
            } else {
                targetOdds.push_back(target[i]);
            }
        }
        auto operationsSteps = 0ll;
        for(auto i = 0; i < numEvens.size(); i++) {
            operationsSteps += std::abs(numEvens[i] - targetEvens[i]) / 2ll;
        }
        for(auto i = 0; i < numOdds.size(); i++) {
            operationsSteps += std::abs(numOdds[i] - targetOdds[i]) / 2ll;
        }
        return operationsSteps / 2ll;
    }
};