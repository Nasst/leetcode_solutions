#include <vector>

class Solution {
public:
    int candy(std::vector<int>& ratings) {
        if(ratings.size() == 1) {
            return 1;
        }
        auto candies = std::vector<int>(ratings.size(), 0);
        auto bottomIndexes = std::vector<int>();
        if(ratings[0] <= ratings[1]) {
            bottomIndexes.push_back(0);
            candies[0] = 1;
        }
        for(auto i = 1; i < ratings.size() - 1; i++) {
            auto prev = ratings[i - 1];
            auto post = ratings[i + 1];
            auto curr = ratings[i];
            if(curr <= prev && curr <= post) {
                candies[i] = 1;
                bottomIndexes.push_back(i);
            }
        }
        if(ratings[ratings.size() - 1] <= ratings[ratings.size() - 2]) {
            bottomIndexes.push_back(ratings.size() - 1);
            candies[candies.size() - 1] = 1;
        }
        for(auto it = bottomIndexes.begin(); it < bottomIndexes.end(); it++) {
            for(auto i = *it - 1; i >= 0; i--) {
                if(ratings[i] > ratings[i + 1]) {
                    if(candies[i] < candies[i + 1] + 1) {
                        candies[i] = candies[i + 1] + 1;
                    }
                    else {
                        break;
                    }
                }
                else {
                    break;
                }
            }
            for(auto i = *it + 1; i < candies.size(); i++) {
                if(ratings[i] > ratings[i - 1]) {
                    if(candies[i] < candies[i - 1] + 1) {
                        candies[i] = candies[i - 1] + 1;
                    }
                    else {
                        break;
                    }
                }
                else {
                    break;
                }
            }
        }
        auto candyTotal = 0;
        for(auto it = candies.begin(); it < candies.end(); it++) {
            candyTotal += *it;
        }
        return candyTotal;
    }
};