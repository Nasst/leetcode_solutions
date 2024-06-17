import 'dart:math';

// I don't know what got into me today, but I wrote completely unreadable code.
// Should have alright performance at least
class Solution {
  int maxArea(List<int> height) {
    var leftIndex = 0;
    var rightIndex = height.length - 1;
    var currentMax =
        (rightIndex - leftIndex) * min(height[leftIndex], height[rightIndex]);
    while (true) {
      if (height[leftIndex] < height[rightIndex]) {
        var prevLeftHeight = height[leftIndex];
        var successFlag = false;
        for (var i = leftIndex + 1; i < rightIndex; i++) {
          if (height[i] > prevLeftHeight) {
            leftIndex = i;
            currentMax = max(currentMax,
                min(height[i], height[rightIndex]) * (rightIndex - i));
            successFlag = true;
            break;
          }
        }
        if (!successFlag) {
          break;
        }
      } else {
        var prevRightHeight = height[rightIndex];
        var successFlag = false;
        for (var i = rightIndex - 1; i > leftIndex; i--) {
          if (height[i] > prevRightHeight) {
            rightIndex = i;
            currentMax = max(currentMax,
                min(height[i], height[leftIndex]) * (i - leftIndex));
            successFlag = true;
            break;
          }
        }
        if (!successFlag) {
          break;
        }
      }
    }
    return currentMax.toInt();
  }
}
