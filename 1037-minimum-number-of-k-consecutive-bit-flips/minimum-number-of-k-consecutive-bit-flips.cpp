#include <bitset>
#include <vector>

class Solution {
public:
    int minKBitFlips(std::vector<int>& nums, int k) {
        auto bits = std::bitset<100000>();
        auto lengthMask = std::bitset<100000>();
        auto flips = std::bitset<100000>();
        for(auto i = 0; i < nums.size(); i++) {
            bits[i] = nums[i];
            lengthMask[i] = 1;
        }
        for(auto i = 0; i < k; i++) {
            flips[i] = 1;
        }
        auto flipCount = 0;
        for(auto i = 0; i < nums.size() + 1 - k; i++) {
            if(!bits[i]) {
                bits ^= flips;
                flipCount++;
            }
            flips <<= 1;
        }
        bits ^= lengthMask;
        if(bits.none()) {
            return flipCount;
        }
        else {
            return -1;
        }
    }
};