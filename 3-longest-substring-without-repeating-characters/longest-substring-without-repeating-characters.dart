class Solution {
  // Probably not very performant, exhaustive search
  int lengthOfLongestSubstring(String s) {
    var charList = s.split("");
    var currMax = 0;
    for (var i = 0; i < charList.length; i++) {
      var charSet = <String>{};
      var substringLength = 0;
      for (var j = i; j < charList.length; j++) {
        if (charSet.add(charList[j])) {
          substringLength++;
        } else {
          break;
        }
      }
      currMax = currMax > substringLength ? currMax : substringLength;
    }
    return currMax;
  }
}