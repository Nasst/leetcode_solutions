class Solution {
  int reverse(int x) {
    var isPositive = x > 0;
    var resultStr = x.abs().toString().split('').reversed.join();
    var result = BigInt.parse(resultStr);
    result = isPositive ? result : result * BigInt.from(-1);
    if (result <= BigInt.from(2147483647) &&
        result >= BigInt.from(-2147483648)) {
      return result.toInt();
    } else {
      return 0;
    }
  }
}
