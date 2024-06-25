#include <algorithm>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        auto currProfit = 0;
        auto buyPrice = prices[0];
        for(auto it = prices.begin() + 1; it < prices.end(); it++) {
            if(*it < buyPrice) {
                buyPrice = *it;
            }
            else {
                currProfit = std::max(currProfit, *it - buyPrice);
            }
        }
        return currProfit;
    }
};