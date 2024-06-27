#include <algorithm>
#include <vector>

class Solution {
public:
    int hIndex(std::vector<int>& citations) {
        std::sort(citations.begin(), citations.end());
        auto max = 0;
        for(auto i = 1; i <= citations.size(); i++) {
            if(citations[citations.size() - i] >= i) {
                max = i;
            }
        }
        return max;
    }
};