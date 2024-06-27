#include <vector>

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        auto total = 0;
        auto runningTotal = 0;
        auto maxNetPositive = 0;
        auto startingIndex = 0;
        for(auto i = 0; i < gas.size(); i++) {
            if(runningTotal < 0) {
                runningTotal = 0;
                startingIndex = i;
            }
            auto netChange = gas[i] - cost[i];
            total += netChange;
            runningTotal += netChange;
        }
        return total >= 0 ? startingIndex : -1;
    }
};