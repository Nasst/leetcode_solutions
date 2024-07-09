#include <string>

class Solution {
public:
    std::string reverseWords(std::string s) {
        auto wordFlag = false;
        auto wordLength = 0;
        auto newString = std::string();
        for(auto i = 0; s.rbegin() + i < s.rend(); i++) {
            auto chara = *(s.rbegin() + i);
            if(chara == ' ') {
                if(wordFlag) {
                    wordFlag = false;
                    if(newString.size() > 0) {
                        newString += ' ';
                    }
                    newString += s.substr(s.size() - i, wordLength);
                    wordLength = 0;
                }
            }
            else if(i == s.size() - 1) {
                if(newString.size() > 0) {
                    newString += ' ';
                }
                newString += s.substr(0, wordLength + 1);
            }
            else {
                wordFlag = true;
                wordLength++;
            }
        }
        return newString;
    }
};