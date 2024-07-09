#include <string>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        auto wordFlag = false;
        auto iter = s.rbegin();
        auto wordLength = 0;
        while(true) {
            if(iter == s.rend()) {
                break;
            }
            else if(*iter == ' ' && wordFlag) {
                break;
            }
            else if(*iter == ' ') {
                iter++;
            }
            else {
                wordFlag = true;
                wordLength++;
                iter++;
            }
        }
        return wordLength;
    }
};