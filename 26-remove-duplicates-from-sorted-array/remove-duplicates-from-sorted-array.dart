import 'dart:collection';

class Solution {
  int removeDuplicates(List<int> nums) {
    var set = HashSet();
    for (var i = 0; i < nums.length;) {
      if (set.contains(nums[i])) {
        nums.removeAt(i);
      } else {
        set.add(nums[i]);
        i++;
      }
    }
    return set.length;
  }
}
