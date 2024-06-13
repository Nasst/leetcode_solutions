class Solution {
  int minMovesToSeat(List<int> seats, List<int> students) {
    seats.sort();
    students.sort();
    var result = 0;
    for (var i = 0; i < seats.length; i++) {
      result += (seats[i] - students[i]).abs();
    }
    return result;
  }
}