import 'dart:collection';

// I feel like there's a less overcomplicated way to do this
// but I can't see it right now.
class Solution {
  List<List<int>> threeSum(List<int> nums) {
    var map = LinkedHashMap<int, int>();
    nums.sort();
    for (var num in nums) {
      if (map.containsKey(num)) {
        map[num] = map[num]! + 1;
      } else {
        map[num] = 1;
      }
    }
    var keyList = map.keys.toList();
    var triplesList = <List<int>>[];
    for (var i = 0; i < keyList.length; i++) {
      if (keyList[i] == 0) {
        if (map[0]! >= 3) {
          triplesList.add([0, 0, 0]);
        }
      } else {
        if (map[keyList[i]]! >= 2) {
          if (map.containsKey(keyList[i] * (-2))) {
            triplesList.add([keyList[i], keyList[i], keyList[i] * (-2)]);
          }
        }
        for (var j = i + 1; j < keyList.length; j++) {
          var thirdNumber = -1 * (keyList[i] + keyList[j]);
          if (thirdNumber <= keyList[i] || thirdNumber <= keyList[j]) {
            continue;
          }
          if (map.containsKey(thirdNumber)) {
            triplesList.add([keyList[i], keyList[j], thirdNumber]);
          }
        }
      }
    }
    return triplesList;
  }
}
