#include <vector>

class Solution {
public:
    int rotateNum(int num, int rotation) {
        return ((num % rotation) + rotation) % rotation;
    }

    int gcd(int num1, int num2) {
        while(num1 != 0 && num2 != 0) {
            if(num1 > num2) {
                num1 %= num2;
            }
            else {
                num2 %= num1;
            }
        }
        return num1 == 0 ? num2 : num1;
    }

    void rotate(std::vector<int>& nums, int k) {
        auto steps = gcd(nums.size(), k);
        for(auto i = 0; i < steps; i++) {
            auto currentStep = i;
            auto nextStep = rotateNum(i - k, nums.size());
            auto mem = nums[i];
            while(nextStep != i) {
                nums[currentStep] = nums[nextStep];
                currentStep = nextStep;
                nextStep = rotateNum(nextStep - k, nums.size());
            }
            nums[currentStep] = mem;
        }
    }
};