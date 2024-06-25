#include <map>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        auto numCount = std::map<int, int>();
        auto read = nums.begin();
        auto write = nums.begin();
        auto k = 0;
        while(read != nums.end()) {
            if(numCount[*read] <= 1) {
                numCount[*read]++;
                *write = *read;
                write++;
                read++;
                k++;
            }
            else {
                read++;
            }
        }
        return k;
    }
};