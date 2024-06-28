#include <algorithm>
#include <iterator>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>


class Solution {
public:
    template <class RandomAccessIterator>
    std::pair<int, int> trapInOneDirection(RandomAccessIterator begin, RandomAccessIterator end) {
        auto queue = std::vector<std::pair<int, int>>();
        queue.emplace_back(std::pair<int, int>(*begin, 0));
        for(auto i = 1; begin + i < end; i++) {
            if(queue.back().first <= *(begin + i)) {
                queue.emplace_back(std::pair<int, int>(*(begin + i), i));
            }
        }
        auto maxIndex = queue.back().second;
        auto waterTotal = 0;
        for(auto it = queue.rbegin(); it < queue.rend() - 1; it++) {
            auto waterHeight = std::min<int>(it->first, (it + 1)->first);
            auto partialWater = 0;
            for(auto i = (it + 1)->second + 1; i < it->second; i++) {
                partialWater += waterHeight - *(begin + i);
            }
            waterTotal += partialWater;
        }
        return std::make_pair(waterTotal, maxIndex);
    }

    int trap(std::vector<int>& height) {
        if(height.size() <= 2) {
            return 0;
        }
        auto partialWater = 0;
        auto maxIndex = 0;
        auto waterTotal = 0;
        std::tie<int, int>(partialWater, maxIndex) = trapInOneDirection(height.begin(), height.end());
        waterTotal += partialWater;
        std::tie<int, int>(partialWater, maxIndex) = trapInOneDirection(height.rbegin(), height.rend() - maxIndex);
        waterTotal += partialWater;
        return waterTotal;
    }
};