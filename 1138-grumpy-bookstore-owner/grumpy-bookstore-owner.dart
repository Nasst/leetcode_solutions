class Solution {
  int reverseGrumpy(int grumpy) {
    return grumpy == 0 ? 1 : 0;
  }

  List<int> maxSatisfactionPeriod(List<int> customers, int minutes) {
    var movingPeriod = 0;
    var resultList = <int>[];
    for (var i = 0; i < minutes; i++) {
      movingPeriod += customers[i];
    }
    resultList.add(movingPeriod);
    for (var i = minutes; i < customers.length; i++) {
      movingPeriod += customers[i];
      movingPeriod -= customers[i - minutes];
      resultList.add(movingPeriod);
    }
    return resultList;
  }

  List<int> currentSatisfactionPeriod(
      List<int> customers, List<int> grumpy, int minutes) {
    var movingPeriod = 0;
    var resultList = <int>[];
    for (var i = 0; i < minutes; i++) {
      movingPeriod += customers[i] * reverseGrumpy(grumpy[i]);
    }
    resultList.add(movingPeriod);
    for (var i = minutes; i < customers.length; i++) {
      movingPeriod += customers[i] * reverseGrumpy(grumpy[i]);
      movingPeriod -=
          customers[i - minutes] * reverseGrumpy(grumpy[i - minutes]);
      resultList.add(movingPeriod);
    }
    return resultList;
  }

  int totalSatisfaction(List<int> customers, List<int> grumpy) {
    var result = 0;
    for (var i = 0; i < customers.length; i++) {
      result += customers[i] * reverseGrumpy(grumpy[i]);
    }
    return result;
  }

  int maxSatisfied(List<int> customers, List<int> grumpy, int minutes) {
    var _maxSatisfactionPeriod = maxSatisfactionPeriod(customers, minutes);
    var _currentSatisfactionPeriod =
        currentSatisfactionPeriod(customers, grumpy, minutes);
    var useGrumpyMinute = 0;
    var maxSatisfactionImprovement = 0;
    for (var i = 0; i < customers.length - minutes + 1; i++) {
      if (_maxSatisfactionPeriod[i] - _currentSatisfactionPeriod[i] >
          maxSatisfactionImprovement) {
        useGrumpyMinute = i;
        maxSatisfactionImprovement =
            _maxSatisfactionPeriod[i] - _currentSatisfactionPeriod[i];
      }
    }
    for (var i = useGrumpyMinute; i < useGrumpyMinute + minutes; i++) {
      grumpy[i] = 0;
    }
    return totalSatisfaction(customers, grumpy);
  }
}