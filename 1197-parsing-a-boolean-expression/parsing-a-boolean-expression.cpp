#include <assert.h>
#include <string>

class Solution {
public:
    bool parseBoolExprAux(std::string& expression, int start, int end) {
        if(expression[start] == 't') {
            return true;
        }
        else if(expression[start] == 'f') {
            return false;
        }
        else if(expression[start] == '!') {
            return !parseBoolExprAux(expression, start + 2, end - 1);
        }
        else if(expression[start] == '&') {
            auto newStart = start + 2;
            auto openParent = 0;
            auto resultExpr = true;
            for(auto i = newStart; i < end; i++) {
                if(expression[i] == '(') {
                    openParent++;
                }
                else if(expression[i] == ')') {
                    openParent--;
                }
                else if(expression[i] == ',' && openParent == 0) {
                    resultExpr = resultExpr && parseBoolExprAux(expression, newStart, i);
                    newStart = i + 1;
                }
            }
            resultExpr = resultExpr &&  parseBoolExprAux(expression, newStart, end - 1);
            return resultExpr;
        }
        else if(expression[start] == '|') {
            auto newStart = start + 2;
            auto openParent = 0;
            auto resultExpr = false;
            for(auto i = newStart; i < end; i++) {
                if(expression[i] == '(') {
                    openParent++;
                }
                else if(expression[i] == ')') {
                    openParent--;
                }
                else if(expression[i] == ',' && openParent == 0) {
                    resultExpr = resultExpr || parseBoolExprAux(expression, newStart, i);
                    newStart = i + 1;
                }
            }
            resultExpr = resultExpr ||  parseBoolExprAux(expression, newStart, end - 1);
            return resultExpr;
        }
        else {
            assert(false);
            return false;
        }
    }

    bool parseBoolExpr(std::string expression) {
        return parseBoolExprAux(expression, 0, expression.size());
    }
};