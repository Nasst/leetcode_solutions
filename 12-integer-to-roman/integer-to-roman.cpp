#include <string>

class Solution {
public:
    std::string intToRoman(int num) {
        auto units = std::string("IXCMQ");
        auto fives = std::string("VLDQ");
        auto resultString = std::string();
        for(auto i = 0; ; i++) {
            if(num == 0) {
                break;
            }
            else {
                auto digit = num % 10;
                num /= 10;
                auto unit = units[i];
                auto nextUnit = units[i + 1];
                auto five = fives[i];
                auto partialString = std::string();
                if(digit == 4) {
                    partialString.push_back(unit);
                    partialString.push_back(five);
                }
                else if(digit == 9) {
                    partialString.push_back(unit);
                    partialString.push_back(nextUnit);
                }
                else {
                    if(digit >= 5) {
                        partialString.push_back(five);
                        digit -=5;
                    }
                    while(digit > 0) {
                        partialString.push_back(unit);
                        digit--;
                    }
                }
                resultString = partialString + resultString;
            }
        }
        return resultString;
    }
};