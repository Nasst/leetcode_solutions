#include <algorithm>
#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        auto mergedNums = std::vector<int>();
        auto iterator1 = nums1.begin();
        auto iterator2 = nums2.begin();
        while(iterator1 < nums1.begin() + m || iterator2 != nums2.end()) {
            if(iterator1 < nums1.begin() + m && iterator2 != nums2.end()) {
                if(*iterator1 < *iterator2) {
                    mergedNums.push_back(*iterator1);
                    iterator1++;
                }
                else {
                    mergedNums.push_back(*iterator2);
                    iterator2++;
                }
            }
            else if(iterator1 < nums1.begin() + m) {
                mergedNums.push_back(*iterator1);
                iterator1++;
            }
            else {
                mergedNums.push_back(*iterator2);
                iterator2++;
            }
        }
        for(auto i = 0; i < nums1.size(); i++) {
            nums1[i] = mergedNums[i];
        }
    }
};