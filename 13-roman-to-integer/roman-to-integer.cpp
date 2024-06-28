#include <map>
#include <string>

std::map<char, int> characterValues = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};

class Solution {
public:
    int romanToInt(std::string s) {
        auto totalValue = 0;
        for(auto it = s.begin(); it < s.end(); it++) {
            auto value = characterValues[*it];
            auto nextChar = it + 1;
            if(nextChar != s.end()) {
                if((*it == 'I' && (*nextChar == 'V' || *nextChar == 'X')) ||
                    (*it == 'X' && (*nextChar == 'L' || *nextChar == 'C')) ||
                    (*it == 'C' && (*nextChar == 'D' || *nextChar == 'M'))) {
                        value *= (-1);
                    }
            }
            totalValue += value;
        }
        return totalValue;
    }
};