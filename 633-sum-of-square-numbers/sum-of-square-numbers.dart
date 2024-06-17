//https://en.wikipedia.org/wiki/Sum_of_two_squares_theorem

class Solution {
  bool judgeSquareSum(int c) {
    if (c == 0) {
      return true;
    }
    while (c % 2 == 0) {
      c ~/= 2;
    }
    var i = 3;
    while (i * i <= c) {
      var count = 0;
      while (c % i == 0) {
        count++;
        c ~/= i;
      }
      if (count % 2 == 1) {
        return false;
      }
      while (c % (i + 2) == 0) {
        c ~/= (i + 2);
      }
      i += 4;
    }
    return c % 4 != 3;
  }
}
