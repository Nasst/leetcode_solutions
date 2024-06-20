class Solution {
  bool tryMax(List<int> position, int m, int thisMax) {
    var lastPosition = position[0];
    m--;
    for (var i = 1; i < position.length && m > 0; i++) {
      if (position[i] - lastPosition >= thisMax) {
        m--;
        lastPosition = position[i];
      }
    }
    return m == 0;
  }

  int maxDistance(List<int> position, int m) {
    position.sort();
    var start = 1;
    var end = position[position.length - 1] - position[0];
    var ans = -1;
    while (start <= end) {
      var midpoint = (start + end) ~/ 2;
      if (tryMax(position, m, midpoint)) {
        ans = midpoint;
        start = midpoint + 1;
      } else {
        end = midpoint - 1;
      }
    }
    return ans;
  }
}
