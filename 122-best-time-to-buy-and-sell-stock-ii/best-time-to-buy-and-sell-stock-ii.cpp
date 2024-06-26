#include <algorithm>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        auto buyPrice = prices[0];
        auto profit = 0;
        for(auto iter = prices.begin() + 1; iter < prices.end(); iter++) {
            if(*iter < *(iter - 1)) {
                profit += std::max(0, *(iter - 1) - buyPrice);
                buyPrice = *iter;
            }
        }
        profit += std::max(0, prices[prices.size() - 1] - buyPrice);
        return profit;
    }
};