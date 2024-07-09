#include <string>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        auto minLength = strs[0].size();
        for(auto it = strs.begin(); it < strs.end(); it++) {
            minLength = std::min(minLength, it->size());
        }
        auto prefixLength = 0;
        for(auto i = 0; i < minLength; i++) {
            auto ch = strs[0][i];
            auto match = true;
            for(auto strIt = strs.begin() + 1; strIt < strs.end(); strIt++) {
                if((*strIt)[i] != ch) {
                    match = false;
                    break;
                }
            }
            if(!match) {
                break;
            }
            else {
                prefixLength++;
            }
        }
        return strs[0].substr(0, prefixLength);
    }
};