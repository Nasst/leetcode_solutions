class Solution {
  static const upperLimit = 2147483647;
  static const lowerLimit = -2147483648;

  int myAtoi(String s) {
    var numPattern = RegExp(r'[-+]?\d+');
    var match = numPattern.matchAsPrefix(s.trimLeft());
    if (match != null) {
      var bigNum = BigInt.parse(match[0]!);
      if (bigNum > BigInt.from(upperLimit)) {
        return upperLimit;
      } else if (bigNum < BigInt.from(lowerLimit)) {
        return lowerLimit;
      } else {
        return bigNum.toInt();
      }
    } else {
      return 0;
    }
  }
}
