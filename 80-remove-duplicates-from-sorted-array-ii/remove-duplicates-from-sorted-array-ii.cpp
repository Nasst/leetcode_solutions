#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        auto prevNumread = nums[0] - 1;
        auto prevNumread2 = nums[0] - 2;
        auto write = nums.begin();
        auto read = nums.begin();
        auto k = 0;
        while(read != nums.end()) {
            if(prevNumread == prevNumread2 && *read == prevNumread) {
                read++;
            }
            else {
                prevNumread2 = prevNumread;
                prevNumread = *read;
                *write = *read;
                write++;
                read++;
                k++;
            }
        }
        return k;
    }
};