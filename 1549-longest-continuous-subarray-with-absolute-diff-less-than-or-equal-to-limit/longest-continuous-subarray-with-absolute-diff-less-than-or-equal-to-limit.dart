import 'dart:collection';
import 'dart:math';

class Solution {
  void addKeyToMap(SplayTreeMap<int, int> map, int key) {
    if (map.containsKey(key)) {
      map[key] = map[key]! + 1;
    } else {
      map[key] = 1;
    }
  }

  void removeKeyFromMap(SplayTreeMap<int, int> map, int key) {
    if (map[key]! == 1) {
      map.remove(key);
    } else {
      map[key] = map[key]! - 1;
    }
  }

  int longestSubarray(List<int> nums, int limit) {
    var start = 0;
    var length = 1;
    var numCollection = SplayTreeMap<int, int>();
    var maxLength = 0;
    numCollection[nums[0]] = 1;
    while (start + length < nums.length) {
      if ((numCollection.lastKey()! - numCollection.firstKey()!).abs() <=
          limit) {
        maxLength = max(maxLength, length);
        addKeyToMap(numCollection, nums[start + length]);
        length++;
      } else {
        removeKeyFromMap(numCollection, nums[start]);
        start++;
        length--;
      }
    }
    if ((numCollection.lastKey()! - numCollection.firstKey()!).abs() <= limit) {
      maxLength = max(maxLength, length);
    }
    return maxLength;
  }
}
